#ifndef FIELDESTABLE_H
#define FIELDESTABLE_H

#include <QDialog>
namespace Ui {
class Ui_fildesTable;
}

class fieldesTable : public QDialog
{
    Q_OBJECT
public:
    explicit fieldesTable(QDialog *parent = nullptr);
     ~fieldesTable();

signals:

public slots:
private:
    Ui::Ui_fildesTable *ui;
};

#endif // FIELDESTABLE_H
