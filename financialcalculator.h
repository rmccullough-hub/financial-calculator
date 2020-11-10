#ifndef FINANCIALCALCULATOR_H
#define FINANCIALCALCULATOR_H

#include <QMainWindow>
#include "qlabel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class financialcalculator; }
QT_END_NAMESPACE

class financialcalculator : public QMainWindow
{
    Q_OBJECT

public:
    financialcalculator(QWidget *parent = nullptr);
    ~financialcalculator();

private:
    Ui::financialcalculator *ui;
    QLabel *btn_pressed = new QLabel;

private slots:
    void back();
    void make_calculation();
    void CompoundInterest();
    void FutureValue();
    void DCF();
    void Amortization();
    void PriceToBook();
    void PriceToDividends();
    void PriceToEarnings();
    void CAPM();
    void CAGR();
    void SimpleInterest();
    void ExpectedReturn();
    void LeverageRatio();
};
#endif // FINANCIALCALCULATOR_H
