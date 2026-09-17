/**
  * \class RatingFieldWizard
  * \brief Wizard class for creation and configuration of image type fields
  * \author Giorgio Wicklein - GIOWISYS Software
  * \date 08/10/2012
  */

#ifndef RatingFieldWizard_H
#define RatingFieldWizard_H


//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------

#include "abstractfieldwizard.h"


//-----------------------------------------------------------------------------
// Forward declarations
//-----------------------------------------------------------------------------

namespace Ui {
class RatingFieldWizard;
}


//-----------------------------------------------------------------------------
// RatingFieldWizard
//-----------------------------------------------------------------------------

class RatingFieldWizard : public AbstractFieldWizard
{
    Q_OBJECT

public:
    explicit RatingFieldWizard(const QString &fieldName,
                              QWidget *parent = nullptr,
                              AbstractFieldWizard::EditMode editMode
                              = AbstractFieldWizard::NewEditMode);
    ~RatingFieldWizard();

    void getFieldProperties(QString &displayProperties,
                            QString &editProperties,
                            QString &triggerProperties);
    void loadField(const int fieldId, const int collectionId);

private:
    Ui::RatingFieldWizard *ui;
};

#endif // RatingFieldWizard_H
