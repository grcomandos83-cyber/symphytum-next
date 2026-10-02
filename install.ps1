Write-Host "Installing Symphytum Next (Latest Release)..." -ForegroundColor Cyan

try {
    # Get latest release data
    $release = Invoke-RestMethod -Uri "https://api.github.com/repos/grcomandos83-cyber/symphytum-next/releases/latest" -ErrorAction Stop

    # Find the windows installer asset
    $asset = $release.assets | Where-Object { $_.name -match "setup\.exe$" } | Select-Object -First 1

    if (-not $asset) {
        Write-Host "Error: Could not find Windows installer in the latest release." -ForegroundColor Red
        exit 1
    }

    $downloadUrl = $asset.browser_download_url
    $tempFile = Join-Path $env:TEMP $asset.name

    Write-Host "Downloading $($asset.name)..." -ForegroundColor Yellow
    Invoke-WebRequest -Uri $downloadUrl -OutFile $tempFile -ErrorAction Stop

    Write-Host "Running installer..." -ForegroundColor Yellow
    $process = Start-Process -FilePath $tempFile -ArgumentList "/VERYSILENT /SUPPRESSMSGBOXES /NORESTART" -Wait -PassThru

    if ($process.ExitCode -eq 0) {
        Write-Host "Symphytum has been successfully installed!" -ForegroundColor Green
    } else {
        Write-Host "Installation failed with exit code $($process.ExitCode)." -ForegroundColor Red
    }

    # Cleanup
    Write-Host "Cleaning up..." -ForegroundColor Gray
    Remove-Item $tempFile -Force -ErrorAction SilentlyContinue

    Write-Host "Done." -ForegroundColor Cyan
} catch {
    Write-Host "An error occurred: $_" -ForegroundColor Red
}
