/**
  * \class RatingFormWidget
  * \brief Form widget to display and input a star rating
  * \author Symphytum Next
  */

#ifndef RATINGFORMWIDGET_H
#define RATINGFORMWIDGET_H

#include "abstractformwidget.h"
#include <QtWidgets/QWidget>

class QVBoxLayout;
class QLabel;
class StarEditor; // Custom widget for stars

class RatingFormWidget : public AbstractFormWidget
{
    Q_OBJECT

public:
    explicit RatingFormWidget(QWidget *parent = nullptr);

    void setFieldName(const QString &name);
    QString getFieldName() const;
    void clearData();
    void setData(const QVariant &data);
    QVariant getData() const;
    void loadMetadataDisplayProperties(const QString &metadata);

protected slots:
    void validateData();

private:
    void setupFocusPolicy();

    QVBoxLayout *m_mainLayout;
    QLabel *m_nameLabel;
    StarEditor *m_starEditor;
};

//-----------------------------------------------------------------------------
// StarEditor
//-----------------------------------------------------------------------------

class StarEditor : public QWidget
{
    Q_OBJECT
public:
    StarEditor(QWidget *parent = nullptr);
    int starCount() const { return m_starCount; }
    void setStarCount(int count);

signals:
    void editingFinished();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    QSize sizeHint() const override;

private:
    int starAtPosition(int x) const;
    int m_starCount;
    int m_maxStarCount;
};

#endif // RATINGFORMWIDGET_H
