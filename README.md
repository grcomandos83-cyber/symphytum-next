[![Release](https://github.com/grcomandos83-cyber/symphytum-next/actions/workflows/release.yml/badge.svg)](https://github.com/grcomandos83-cyber/symphytum-next/actions/workflows/release.yml)
[![License](https://img.shields.io/badge/License-BSD_2--Clause-blue.svg)](https://opensource.org/licenses/BSD-2-Clause)
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/grcomandos83-cyber/symphytum-next)](https://github.com/grcomandos83-cyber/symphytum-next/releases/latest)

![logo](https://raw.githubusercontent.com/grcomandos83-cyber/symphytum-next/master/stuff/logo/symphytum_64.png "Symphytum")
# Symphytum Next

> **Project Status & Maintenance Notice:**  
> This repository is the official standalone continuation, modernization, and maintenance fork of the original [Symphytum](https://github.com/giowck/symphytum) personal database application. Development, modern Qt updates, fixes, and multi-platform release packaging are actively maintained by [grcomandos83-cyber](https://github.com/grcomandos83-cyber).

Symphytum Next is a personal database software for everyone who desires to manage and organize data in an easy and intuitive way, without having to study complex database languages and software user interfaces.        

**Table of Contents**
* [Introduction](#introduction)
    * [Features](#features)
    * [How it Looks](#how-it-looks)
* [Download](#download)
    * [Windows](#windows)
    * [macOS](#macos)
        * [Disk Image (.dmg)](#1-macos-disk-image-dmg)
        * [Portable ZIP Bundle](#2-macos-portable-zip-bundle)
    * [Linux](#linux)
        * [Portable Tarball (.tar.gz)](#1-linux-portable-archive-targz)
* [Changelog & Version History](#changelog--version-history)
* [Contribute](#contribute)
* [License](#license)

## Introduction
Symphytum is a free and open-source personal database software written in C++ and Qt for Windows, macOS and Linux. Design and edit simple databases in a visual and intuitive way, without any need to study complex database languages. Symphytum is directed at users who just want to organize data in custom designed collections without giving up advantages of database engines like fast loading speed, large data set handling, fast searching, sorting and more.

Manage all kind of data ranging from contacts, inventory, any type of collection, customers and so on. There are limitations though, Symphytum is not able to handle relational data and automatic field calculations yet. Also the import from CSV files is very limited, all imported data sets are handled just as text fields, future improvements to the import dialog, to specify each field type, are planned though.

Symphytum is able to synchronise your data through different cloud services like Dropbox or MEGA. It can detect and handle sync conflicts in case multiple user are using the same database via a supported cloud service.

Technically Symphytum is powered by the SQLite database engine, which is the leading embedded database solution, used in many mobile apps and modern computer programs, like web browsers, media players and email clients.
SQLite is tiny, efficient and very fast. It can handle huge amount of data while being highly resistant to data corruption. 

### Features
* **Fields Are Not Just Text**. Design your input forms with support for different data types: text, numeric, date, progress, image, file list, checkbox, combobox, etc.
* **Two Views On The Same Data**. Use the form view for structured data input and representation, use the table-like view for searching, sorting and comparing.
* **Dynamic Layout Engine**. Rearrange dynamically your database layout by drag and drop in form view.
* **Integrated Cloud Sync**. Using Symphytum across multiple computers is a joy. Your data is always automatically synchronised everywhere. Drivers for cloud services such as Dropbox and MEGA are included.
* **Sync Conflict Management**. Symphytum manages synchronisation conflicts for you. While only one session with write access is allowed at the same time, other computers may access the database in read-only mode during an open session.
* **Date Reminder**. Date fields keep you informed on tasks, appointments or birthdays, if requested. All Reminders, once triggered, are listed in one place.
* **Fast Search**. Search while typing with highlighted results in a table view.
* **Backup and Export**. Backup your data with a simple backup wizard and export your data to CSV.
* **Multilingual**. User interface available in English, German, Polish, French, Italian and Greek.


### How it Looks
Some screenshots showing the form view, table view, dynamic layout engine and the field addition dialog.

![form_view_img](https://raw.githubusercontent.com/grcomandos83-cyber/symphytum-next/master/stuff/screenshots/mainwindow.png "Form view")
![table_view_img](https://raw.githubusercontent.com/grcomandos83-cyber/symphytum-next/master/stuff/screenshots/tablieview.png "Table view")
![dynamic_layout_img](https://raw.githubusercontent.com/grcomandos83-cyber/symphytum-next/master/stuff/screenshots/dynamic_layout.gif "Dynamic layout engine")

![add_field_img](https://raw.githubusercontent.com/grcomandos83-cyber/symphytum-next/master/stuff/screenshots/addfield.png "Add field")

## Download
Please see the appropriate download section for your operating system below.
General releases, binary packages, and source archives can be found on the [releases](https://github.com/grcomandos83-cyber/symphytum-next/releases) page. Detailed version notes are available in the [CHANGELOG.md](CHANGELOG.md). Thank you for downloading Symphytum Next.

### Windows
For Windows 7, 8, 10, and 11 (64-bit)

Standard Windows installer with desktop shortcut and uninstaller support:

Download [symphytum-2.8-setup.exe](https://github.com/grcomandos83-cyber/symphytum-next/releases/download/v2.8/symphytum-2.8-setup.exe)

### Linux
For modern Linux distributions (Ubuntu, Fedora, Debian, etc)

#### 1. Linux Portable Archive (.tar.gz)
Self-contained pre-compiled binaries and desktop integration resources:

Download [Symphytum-2.8-Linux-x86_64.tar.gz](https://github.com/grcomandos83-cyber/symphytum-next/releases/download/v2.8/Symphytum-2.8-Linux-x86_64.tar.gz)

### macOS
For macOS High Sierra (10.13) and later

#### 1. macOS Disk Image (.dmg)
Contains the .app bundle, drag and drop into the Applications folder:

Download [Symphytum-2.8-macOS.dmg](https://github.com/grcomandos83-cyber/symphytum-next/releases/download/v2.8/Symphytum-2.8-macOS.dmg)

---

## Changelog & Version History
For the complete list of changes, new features, bug fixes, and release history across all versions, please refer to the **[CHANGELOG.md](CHANGELOG.md)** or check the GitHub [Releases](https://github.com/grcomandos83-cyber/symphytum-next/releases) page.

## Contribute
Report an issue, bug or feature proposal at the [project's issue tracker](https://github.com/grcomandos83-cyber/symphytum-next/issues).

## License
Symphytum is licensed under the BSD 2-Clause License, see [LICENSE](https://github.com/grcomandos83-cyber/symphytum-next/blob/master/LICENSE). 
You can use Symphytum for free and for any purpose.

Copyright (c) 2026 grcomandos83-cyber  
Copyright (c) 2014-2020 Symphytum Developers  
Copyright (c) 2012-2014 GIOWISYS Software UG
