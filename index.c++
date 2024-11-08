#include <iostream>//Used for cout and cin
#include <cmath>//Used for Pow function
#include <cstdlib>//Used for exit(1) function
#include <iomanip>// Used for setw function
using namespace std;// allows me to not have to enter std::
void opening();//This function greets the user
void input(double &apr, double &P, int &N);// This function gets the users inputs for APR, loan term, and loan amount
double monthly_interest_rate(double apr, double &R);// This functions calculates the monthly interest rate and displays it.
double ammortization(double P, double R, int N, double &ammort);// This function calculates the ammortization
void monthly_acummulation(double P, double R, double N, double ammort, int &n,double &beginning_balance, double &interest, double &principle, double &Tot_interest, double Tot_principle, double &True_tot_principle);// This function calculates the monthly accumulation of the interest and principal balance as well as it calculates the total payment and total interest in the span of the loan term

void summary(double Tot_interest, double True_tot_principle,double ammort);// This function displays the ammortization, total interest accrued, total principal over the span of the term and the monthly payment.

int main() {
    char choice;
    int N, n;
    double apr, R, P, ammort, beginning_balance, interest, principle, Tot_interest, Tot_principle, True_tot_principle;//defined variables
    opening();//calls this function and runs it
    input(apr, P, N);//calls this function and runs it
    if (apr > 0 and P > 0 and N > 0){// as long as conditions are met then the functions inside the block of code will run
        monthly_interest_rate(apr, R);//calls this function and runs it
        ammortization(P,R ,N , ammort);//calls this function and runs it
        monthly_acummulation(P, R,N, ammort, n, beginning_balance, interest, principle,Tot_interest, Tot_principle, True_tot_principle);//calls this function and runs it
        summary(Tot_interest, True_tot_principle,ammort);//calls this function and runs it
    }
    else{//if conditions aren't met then the program will exit with code 1
        exit(1);
    }
    cout << "\nWould you like to continue (Y/N): ";//prompts user
    
    cin >> choice;
    cout <<"\n.............................................\n";
    while(choice == 'Y'){// while loop that says as long as condition is equal to Y then the code inside will loop until that condition is no longer met.
        input(apr, P, N);//calls this function and runs it
        if (apr > 0 and P > 0 and N > 0){// if apr ,P, and N are greater than 0 then code inside the block will run
            monthly_interest_rate(apr, R);//calls this function and runs it
            ammortization(P,R ,N , ammort);//calls this function and runs it
            monthly_acummulation(P, R,N, ammort, n, beginning_balance, interest, principle,Tot_interest, Tot_principle, True_tot_principle);//calls this function and runs it
            summary(Tot_interest, True_tot_principle,ammort);//calls this function and runs it
        }
        else{//if conditions aren't met then the program will exit with code 1
            exit(1);
        }
        cout << "\nWould you like to continue (Y/N): " << endl;// updates the while loop
        cin >> choice; // gets user input
        cout <<"\n.............................................\n"; // this is meant for organization and neatness
        cout << endl; //ends line
    }
    return 0;
}
void opening(){// This function greets the user without returning any value
    cout <<"Welcome to the loan calculator."<< endl;// welcomes user
    cout <<"\n.............................................\n";
}
void input(double &apr, double &P, int &N){// This function gets the users inputs for APR, loan term, and loan amount
    cout <<"\nEnter the Annual Percentage Rate: ";
    cin >> apr;
    cout <<"\n.............................................\n";
    cout <<"\nEnter the principal loan amount needed: ";
    cin >> P;
    cout <<"\n.............................................\n";
    cout <<"\nEnter the loan term: ";
    cin >> N;
    cout <<"\n.............................................\n";
}
double monthly_interest_rate(double apr, double &R) {// This functions calculates the monthly interest rate and displays it.
    
    R = (pow(1 + apr/100, 1.0/12.0) - 1);//equation to find the interest rate
    cout << "Monthly Interest Rate: %" << R << endl;
    cout <<"\n.............................................\n";
    return R;
    
    
}
double ammortization(double P, double R, int N, double &ammort){// This function calculates the ammortization
    ammort =  P * (R * (pow(1 + R, N)) / (pow(1 + R, N) - 1));//equation to find the monthly payment
    return ammort;
}
void monthly_acummulation(double P, double R, double N, double ammort, int &n,double &beginning_balance, double &interest, double &principle, double &Tot_interest, double Tot_principle, double &True_tot_principle)// This function calculates the monthly accumulation of the interest and principal balance as well as it calculates the total payment and total interest in the span of the loan term
{
    interest = 0;
    principle = 0;
    beginning_balance = P;
    Tot_interest = 0;
    Tot_principle = 0;
    //lines 90-94 are initialized variables
    cout << " Month |Beginning Balance | Interest | Principal | Ending Balance " << endl;
    
    for (n = 1;n <= N;n++){//This is a for loop that is meant to update every month and beginning and ending balance by incrementing itself by every month in accordance to the loan term. in every increment the equations inside the loop will update.
        interest = P*R;//finds the interest
        principle = ammort - interest;//finds the principle
        P -= principle;// finds the ending balance
        Tot_interest += interest;// finds the total overall interest
        Tot_principle += principle;// gets the loan principal amount
        True_tot_principle = Tot_principle + Tot_interest;// adds the loan principal amount and total interest together in order to get the Total amount spent paying the loan off
        
        if (n > 1){//if statement that say if the month is greater than one then it will add the ending balance and the principle in order to find a new beginning balance for each month
            beginning_balance = P + principle; // equation to find each months beginning balance
        }
        
        cout << "__________________________________________________________________" << endl;
        cout << fixed << setprecision(2) <<setw(3) << n << setw(15) << beginning_balance << setw(15) << interest << setw(15) << principle << setw(15) << P << endl;// cout statement using the setw function in order to print each variable neatly in a column
        
    }
}
void summary(double Tot_interest, double True_tot_principle, double ammort){// This function displays the ammortization, total interest accrued, total principal over the span of the term and the monthly payment.
    cout << endl << endl<< endl<< endl;
    cout << "\nTotal Interest accumulated: $" << Tot_interest << endl;
    cout <<"\n.............................................\n";
    cout << "\nTotal Payment: $" << True_tot_principle << endl;
    cout <<"\n.............................................\n";
    cout << fixed << setprecision(2) <<"\nMonthly Payment: $" << ammort << endl;//setprecision is used in order to set the decimal places in a specific order
    cout <<"\n.............................................\n";
    //This whole block of code displays the total interest, total payments and monthly payments using the cout function.

}
