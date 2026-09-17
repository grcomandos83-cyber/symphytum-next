#include "ratingformwidget.h"
#include <QHBoxLayout>
#include <cmath>
#include "../../utils/formwidgetvalidator.h"
#include "../../components/metadataengine.h"

#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtGui/QPainter>
#include <QtGui/QMouseEvent>
#include <QtCore/QVariant>
#include <cmath>

//-----------------------------------------------------------------------------
// RatingFormWidget
//-----------------------------------------------------------------------------

RatingFormWidget::RatingFormWidget(QWidget *parent) :
    AbstractFormWidget(parent)
{
    m_mainLayout = new QVBoxLayout(this);
    m_nameLabel = new QLabel(this);
    m_starEditor = new StarEditor(this);

    m_mainLayout->addWidget(m_nameLabel);
    m_mainLayout->addWidget(m_starEditor);

    this->heightUnits = 1;
    this->widthUnits = 1;

    connect(m_starEditor, SIGNAL(editingFinished()),
            this, SLOT(validateData()));

    setupFocusPolicy();
}

void RatingFormWidget::setFieldName(const QString &name)
{
    m_nameLabel->setText(name);
}

QString RatingFormWidget::getFieldName() const
{
    return m_nameLabel->text();
}

void RatingFormWidget::clearData()
{
    m_starEditor->setStarCount(0);
}

void RatingFormWidget::setData(const QVariant &data)
{
    m_starEditor->setStarCount(data.toInt());
}

QVariant RatingFormWidget::getData() const
{
    return m_starEditor->starCount();
}

void RatingFormWidget::loadMetadataDisplayProperties(const QString &metadata)
{
    Q_UNUSED(metadata);
}

void RatingFormWidget::validateData()
{
    emit dataEdited();
}

void RatingFormWidget::setupFocusPolicy()
{
    m_starEditor->setFocusPolicy(Qt::StrongFocus);
    setFocusProxy(m_starEditor);
    setFocusPolicy(Qt::StrongFocus);
}

//-----------------------------------------------------------------------------
// StarEditor
//-----------------------------------------------------------------------------

const int PaintingScaleFactor = 20;

StarEditor::StarEditor(QWidget *parent)
    : QWidget(parent), m_starCount(0), m_maxStarCount(5)
{
    setMouseTracking(true);
    setAutoFillBackground(true);
}

void StarEditor::setStarCount(int count)
{
    if (count != m_starCount) {
        m_starCount = count;
        update();
    }
}

QSize StarEditor::sizeHint() const
{
    return QSize(m_maxStarCount * PaintingScaleFactor, PaintingScaleFactor);
}

void StarEditor::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);
    painter.setBrush(palette().text());

    QPolygonF starPolygon;
    starPolygon << QPointF(1.0, 0.5);
    for (int i = 1; i < 5; ++i)
        starPolygon << QPointF(0.5 + 0.5 * std::cos(0.8 * i * 3.14159265),
                               0.5 + 0.5 * std::sin(0.8 * i * 3.14159265));

    int yOffset = (height() - PaintingScaleFactor) / 2;
    painter.translate(0, yOffset);

    for (int i = 0; i < m_maxStarCount; ++i) {
        if (i < m_starCount) {
            painter.save();
            painter.translate(i * PaintingScaleFactor, 0);
            painter.scale(PaintingScaleFactor, PaintingScaleFactor);
            painter.drawPolygon(starPolygon, Qt::WindingFill);
            painter.restore();
        } else {
            painter.save();
            painter.translate(i * PaintingScaleFactor, 0);
            painter.scale(PaintingScaleFactor, PaintingScaleFactor);
            painter.setBrush(palette().windowText().color().lighter(300));
            painter.drawPolygon(starPolygon, Qt::WindingFill);
            painter.restore();
        }
    }
}

void StarEditor::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        int stars = starAtPosition(event->x());
        if (stars != m_starCount && stars != -1) {
            m_starCount = stars;
            update();
            emit editingFinished();
        }
    }
    QWidget::mouseReleaseEvent(event);
}

void StarEditor::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
}

int StarEditor::starAtPosition(int x) const
{
    int star = (x / PaintingScaleFactor) + 1;
    if (star <= 0 || star > m_maxStarCount)
        return -1;
    return star;
}
