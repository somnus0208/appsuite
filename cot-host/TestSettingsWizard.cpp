#include <QtWidgets/QWizard>
#include <QtWidgets/QMessageBox>

#include <QAbstractButton>

#include "TestSettingsWizard.h"

#include "HostSettingsWizardPage.h"
#include "TargetSettingsWizardPage.h"

TestSettingsWizard::TestSettingsWizard(QWidget* parent) : 
    Wizard(parent)
{
	setPage(Page_HostSettings, new HostSettingsWizardPage);
	setPage(Page_TargetSettings, new TargetSettingsWizardPage);
	
	setStartId(Page_HostSettings);
}

