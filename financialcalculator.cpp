#include "financialcalculator.h"
#include "ui_financialcalculator.h"
#include <cmath>
#include <vector>
#include <iostream>
#include "equations.cpp"

using namespace std;

financialcalculator::financialcalculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::financialcalculator)
{
    ui->setupUi(this);

    //pixmap loads the background image
    QPixmap pixmap;
    pixmap.load(":/Resources/background.jpg");
    QPalette palette;
    palette.setBrush(QPalette::Window, pixmap);
    this->setPalette(palette);

    ui->stackedWidget->setCurrentIndex(0);

    //backButtons holds the pointer to all back buttons in the application
    //this for loop connects each back button to the back() function, which sets the page index back to 0
    /*
    QPushButton *backButtons[12];
    for(int i = 0; i <= 12; i++){
        QString butName = "Back_" + QString::number(i);
        backButtons[i] = financialcalculator::findChild<QPushButton *>(butName);
        connect(backButtons[i], SIGNAL(released()), this, SLOT(back()));
    }
    */
    connect(ui->Back, SIGNAL(released()), this, SLOT(back()));
    connect(ui->Back_2, SIGNAL(released()), this, SLOT(back()));
    connect(ui->Back_3, SIGNAL(released()), this, SLOT(back()));
    connect(ui->Back_4, SIGNAL(released()), this, SLOT(back()));
    connect(ui->Back_5, SIGNAL(released()), this, SLOT(back()));
    connect(ui->Back_6, SIGNAL(released()), this, SLOT(back()));
    connect(ui->Back_7, SIGNAL(released()), this, SLOT(back()));
    connect(ui->Back_8, SIGNAL(released()), this, SLOT(back()));
    connect(ui->Back_9, SIGNAL(released()), this, SLOT(back()));
    connect(ui->Back_10, SIGNAL(released()), this, SLOT(back()));
    connect(ui->Back_11, SIGNAL(released()), this, SLOT(back()));
    connect(ui->Back_12, SIGNAL(released()), this, SLOT(back()));

    connect(ui->CompoundInterest, SIGNAL(released()), this, SLOT(CompoundInterest()));
    connect(ui->SimpleInterest, SIGNAL(released()), this, SLOT(SimpleInterest()));
    connect(ui->CAPM, SIGNAL(released()), this, SLOT(CAPM()));
    connect(ui->CAGR, SIGNAL(released()), this, SLOT(CAGR()));
    connect(ui->Amortization, SIGNAL(released()), this, SLOT(Amortization()));
    connect(ui->ExpectedReturn, SIGNAL(released()), this, SLOT(ExpectedReturn()));
    connect(ui->LeverageRatio, SIGNAL(released()), this, SLOT(LeverageRatio()));
    connect(ui->PriceToBook, SIGNAL(released()), this, SLOT(PriceToBook()));
    connect(ui->PriceToEarnings, SIGNAL(released()), this, SLOT(PriceToEarnings()));
    connect(ui->PriceToDividends, SIGNAL(released()), this, SLOT(PriceToDividends()));
    connect(ui->DCF, SIGNAL(released()), this, SLOT(DCF()));
    connect(ui->FutureValue, SIGNAL(released()), this, SLOT(FutureValue()));





}

financialcalculator::~financialcalculator()
{
    delete ui;
}


//makes sure the input is not empty
bool validate(vector<string> inputs){
    bool valid_input = true;
    for(int i = 0; i <= (int) inputs.size(); i++){
        if(inputs[i].empty()) valid_input = false;
    }

    return valid_input;
}

//called when a "Calculate" button is pressed
void financialcalculator::make_calculation(){

    string btn_text = btn_pressed->text().toLocal8Bit().constData();
    equations c;

    if(btn_text == "Compound Interest"){
        string input1 = ui->CIPrincipal->text().toLocal8Bit().constData();
        string input2 = ui->CIInterest->text().toLocal8Bit().constData();
        string input3 = ui->CICompounding->text().toLocal8Bit().constData();
        string input4 = ui->CITime->text().toLocal8Bit().constData();

        vector<string> inputs = {input1, input2, input3, input4};

        if(validate(inputs)){
            double ans = c.compound_interest(stod(input1), stod(input2), stod(input3), stod(input4));
            QString valueAsString = QString::number(ans);
            ui->CompoundInterestAnswer->setText(valueAsString);
        }



    } else if(btn_text == "Simple Interest"){
        string input1 = ui->SIPrincipal->text().toLocal8Bit().constData();
        string input2 = ui->SIInterest->text().toLocal8Bit().constData();
        string input3 = ui->SITime->text().toLocal8Bit().constData();

        vector<string> inputs = {input1, input2, input3};
        if(validate(inputs)){
            double ans = c.simple_interest(stod(input1), stod(input2), stod(input3));
            QString valueAsString = QString::number(ans);
            ui->SimpleInterestAnswer->setText(valueAsString);
        }

    } else if(btn_text == "DCF"){
        string input1 = ui->DCFInterest->text().toLocal8Bit().constData();
        string input2 = ui->CashFlowYear1->text().toLocal8Bit().constData();
        string input3 = ui->CashFlowYear2->text().toLocal8Bit().constData();
        string input4 = ui->CashFlowYear3->text().toLocal8Bit().constData();
        string input5 = ui->CashFlowYear4->text().toLocal8Bit().constData();

        vector<string> inputs = {input1, input2, input3, input4, input5};

        if(validate(inputs)){
            vector<float> cash_flows = {stof(input2), stof(input3), stof(input4), stof(input5)};
            double ans = c.dcf(cash_flows, stoi(input1));
            QString valueAsString = QString::number(ans);
            ui->DCFAnswer->setText(valueAsString);
        }

    } else if(btn_text == "Amortization"){
        string input1 = ui->APrincipal->text().toLocal8Bit().constData();
        string input2 = ui->AInterest->text().toLocal8Bit().constData();
        string input3 = ui->APeriods->text().toLocal8Bit().constData();

        vector<string> inputs = {input1, input2, input3};

        if(validate(inputs)){
            double ans = c.amortization(stod(input1), stof(input2), stoi(input3));
            QString valueAsString = QString::number(ans);
            ui->AmortizationAnswer->setText(valueAsString);
        }

    } else if(btn_text == "Price To Book Ratio"){
        string input1 = ui->PBPrice->text().toLocal8Bit().constData();
        string input2 = ui->PBBook->text().toLocal8Bit().constData();

        vector<string> inputs = {input1, input2};

        if(validate(inputs)){
            double ans = c.price_ratio(stod(input1), stod(input2));
            QString valueAsString = QString::number(ans);
            ui->PriceToBookAnswer->setText(valueAsString);
        }

    } else if(btn_text == "Price To Earnings Ratio"){
        string input1 = ui->PEPrice->text().toLocal8Bit().constData();
        string input2 = ui->PEEarnings->text().toLocal8Bit().constData();

        vector<string> inputs = {input1, input2};

        if(validate(inputs)){
            double ans = c.price_ratio(stod(input1), stod(input2));
            QString valueAsString = QString::number(ans);
            ui->PriceToEarningsAnswer->setText(valueAsString);
        }


    } else if(btn_text == "Price To Dividends Ratio"){
        string input1 = ui->PDPrice->text().toLocal8Bit().constData();
        string input2 = ui->PDDividends->text().toLocal8Bit().constData();

        vector<string> inputs = {input1, input2};

        if(validate(inputs)){
            double ans = c.price_ratio(stod(input1), stod(input2));
            QString valueAsString = QString::number(ans);
            ui->PriceToDividendsAnswer->setText(valueAsString);
        }


    } else if(btn_text == "CAPM"){
        string input1 = ui->CAPMInterest->text().toLocal8Bit().constData();
        string input2 = ui->CAPMBeta->text().toLocal8Bit().constData();
        string input3 = ui->CAPMExpected->text().toLocal8Bit().constData();

        vector<string> inputs = {input1, input2, input3};

        if(validate(inputs)){
            double ans = c.capm(stoi(input1), stof(input2), stoi(input3));
            QString valueAsString = QString::number(ans);
            ui->CAPMAnswer->setText(valueAsString);
        }

    } else if(btn_text == "CAGR"){
        string input1 = ui->CAGRBeginning->text().toLocal8Bit().constData();
        string input2 = ui->CAGRFinal->text().toLocal8Bit().constData();
        string input3 = ui->CAGRTime->text().toLocal8Bit().constData();

        vector<string> inputs = {input1, input2, input3};

        if(validate(inputs)){
            double ans = c.cagr(stod(input1), stod(input2), stod(input3));
            QString valueAsString = QString::number(ans);
            ui->CAGRAnswer->setText(valueAsString);
        }

    } else if(btn_text == "Expected Return"){

        string input1 = ui->ERStock1->text().toLocal8Bit().constData();
        string input2 = ui->SWStock1->text().toLocal8Bit().constData();
        string input3 = ui->ERStock2->text().toLocal8Bit().constData();
        string input4 = ui->SWStock2->text().toLocal8Bit().constData();
        string input5 = ui->ERStock3->text().toLocal8Bit().constData();
        string input6 = ui->SWStock3->text().toLocal8Bit().constData();
        string input7 = ui->ERStock4->text().toLocal8Bit().constData();
        string input8 = ui->SWStock4->text().toLocal8Bit().constData();
        string input9 = ui->ERStock5->text().toLocal8Bit().constData();
        string input10 = ui->SWStock5->text().toLocal8Bit().constData();

        vector<string> inputs = {input1, input2, input3, input4, input5, input6, input7, input8, input9, input10};

        if(validate(inputs)){
            int stock1[2] = {stoi(input1), stoi(input2)};
            int stock2[2] = {stoi(input3), stoi(input4)};
            int stock3[2] = {stoi(input5), stoi(input6)};
            int stock4[2] = {stoi(input7), stoi(input8)};
            int stock5[2] = {stoi(input9), stoi(input10)};

            double ans = c.expected_return(stock1, stock2, stock3, stock4, stock5);
            QString valueAsString = QString::number(ans);
            ui->ExpectedReturnAnswer->setText(valueAsString);
        }


    } else if(btn_text == "Future Value"){

        string input1 = ui->FVPrincipal->text().toLocal8Bit().constData();
        string input2 = ui->FVInterest->text().toLocal8Bit().constData();
        string input3 = ui->FVTime->text().toLocal8Bit().constData();

        vector<string> inputs = {input1, input2, input3};

        if(validate(inputs)){
            double ans = c.future_value(stod(input1), stoi(input2), stoi(input3));
            QString valueAsString = QString::number(ans);
            ui->FutureValueAnswer->setText(valueAsString);
        }


    } else {

        string input1 = ui->LRDebt->text().toLocal8Bit().constData();
        string input2 = ui->LRAssets->text().toLocal8Bit().constData();

        vector<string> inputs = {input1, input2};

        if(validate(inputs)){

            double ans = c.leverage_ratio(stod(input1), stod(input2));
            QString valueAsString = QString::number(ans);
            ui->LeverageRatioAnswer->setText(valueAsString);
        }

    }




}

//the following functions are responsible for changing the page
void financialcalculator::back(){
    ui->stackedWidget->setCurrentIndex(0);
    btn_pressed->setText("");

}

void financialcalculator::CompoundInterest(){

    ui->stackedWidget->setCurrentIndex(6);
    btn_pressed->setText("Compound Interest");
    connect(ui->Calculate_6, SIGNAL(released()), this, SLOT(make_calculation()));

}
void financialcalculator::FutureValue(){

    ui->stackedWidget->setCurrentIndex(1);
    btn_pressed->setText("Future Value");
    connect(ui->Calculate, SIGNAL(released()), this, SLOT(make_calculation()));

}
void financialcalculator::DCF(){

    ui->stackedWidget->setCurrentIndex(4);
    btn_pressed->setText("DCF");
    connect(ui->Calculate_4, SIGNAL(released()), this, SLOT(make_calculation()));


}
void financialcalculator::Amortization(){

    ui->stackedWidget->setCurrentIndex(9);
    btn_pressed->setText("Amortization");
    connect(ui->Calculate_9, SIGNAL(released()), this, SLOT(make_calculation()));


}
void financialcalculator::PriceToBook(){

    ui->stackedWidget->setCurrentIndex(3);
    btn_pressed->setText("Price To Book Ratio");
    connect(ui->Calculate_3, SIGNAL(released()), this, SLOT(make_calculation()));

}
void financialcalculator::PriceToDividends(){

    ui->stackedWidget->setCurrentIndex(5);
    btn_pressed->setText("Price To Dividends Ratio");
    connect(ui->Calculate_5, SIGNAL(released()), this, SLOT(make_calculation()));

}
void financialcalculator::PriceToEarnings(){

    ui->stackedWidget->setCurrentIndex(2);
    btn_pressed->setText("Price To Earnings Ratio");
    connect(ui->Calculate_2, SIGNAL(released()), this, SLOT(make_calculation()));


}
void financialcalculator::CAPM(){

    ui->stackedWidget->setCurrentIndex(12);
    btn_pressed->setText("CAPM");
    connect(ui->Calculate_12, SIGNAL(released()), this, SLOT(make_calculation()));


}
void financialcalculator::CAGR(){


    ui->stackedWidget->setCurrentIndex(11);
    btn_pressed->setText("CAGR");
    connect(ui->Calculate_11, SIGNAL(released()), this, SLOT(make_calculation()));

}
void financialcalculator::SimpleInterest(){

    ui->stackedWidget->setCurrentIndex(7);
    btn_pressed->setText("Simple Interest");
    connect(ui->Calculate_7, SIGNAL(released()), this, SLOT(make_calculation()));


}
void financialcalculator::ExpectedReturn(){

    ui->stackedWidget->setCurrentIndex(8);
    btn_pressed->setText("Expected Return");
    connect(ui->Calculate_8, SIGNAL(released()), this, SLOT(make_calculation()));

}
void financialcalculator::LeverageRatio(){

    ui->stackedWidget->setCurrentIndex(10);
    btn_pressed->setText("Leverage Ratio");
    connect(ui->Calculate_10, SIGNAL(released()), this, SLOT(make_calculation()));


}

