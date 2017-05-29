#ifndef EXCLUSIVEBUTTONGROUP_H
#define EXCLUSIVEBUTTONGROUP_H

#include <QObject>
#include <QButtonGroup>

class ExclusiveButtonGroup : public QButtonGroup
{
public:
	ExclusiveButtonGroup();

public slots:
	void updateButtons();

private:
	int pressed_button_;
};

#endif // EXCLUSIVEBUTTONGROUP_H
