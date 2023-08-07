#ifndef ABSOLUTELAYOUT_H
#define ABSOLUTELAYOUT_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class absoluteLayout; }
QT_END_NAMESPACE

class absoluteLayout : public QDialog
{
    Q_OBJECT

public:
    absoluteLayout(QWidget *parent = nullptr);
    ~absoluteLayout();

private:
    Ui::absoluteLayout *ui;
};
#endif // ABSOLUTELAYOUT_H
