for(int i = 1; i <=numberOfYears * 12; i++)
  {
    interest = monthlyInterestRate * balance;
    principal = monthlyPayment - interest;
    balance -= principal;
    printf("%d\t%.2f\t%.2f\t%.2f\t\n",i, interest, principal, balance);
  }