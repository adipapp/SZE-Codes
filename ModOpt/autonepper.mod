param nDays;
param nGarage;
set Cars;
set Days := 1..nDays;
param price{Cars, Days};
param initBudget;
param interestRate;

var buy{Cars, Days} integer;
var money{0..nDays} >= 0;
var loan{0..nDays};

#s.t. DontOverBuy{d in Days}:
#	initBudget - sum{n in 1..d} sum{c in Cars} price[c, n] * buy[c,n] >= 0;

s.t. DontSellScan{c in Cars, d in Days}:
	sum{n in 1..d} buy[c,n] >= 0;

s.t. GarageCapacity{d in Days}:
	sum{c in Cars} sum{n in 1..d} buy[c,n] <= nGarage;

s.t. InitilizeMoney:
	money[0] = initBudget;

s.t. CalculateMoney{d in Days}:
	money[d] = money[d-1] - sum{c in Cars} price[c,d] * buy[c,d] + loan[d-1] - loan[d];

s.t. InitilizeLoan:
	loan[0] = 0;

s.t. BankLoan{d in Days}:
	loan[d] = loan[d-1] * interestRate;

s.t. CheckLoan:
	loan[nDays] = 0;

maximize MoneyAtTheEnd:
	initBudget - sum{c in Cars, d in Days} price[c,d] * buy[c,d];

solve;

printf "Vegso egyenleg: %g\n", MoneyAtTheEnd > "result.txt";

for{d in Days, c in Cars: buy[c,d] != 0} {
	printf "%g.nap vettem: %g db %s-t\n", d, buy[c,d], c >> "result.txt";
}

data;

param initBudget := 30;
param nDays := 5;
param nGarage := 4;
param interestRate := 1.001;
set Cars := Audi Subaru Ford Skoda Honda;
#set Days := 1..nDays;
param price: 1	2	3	4	5 :=
Audi		10	11	9	7	8
Subaru		8	9	10	11	12
Ford		9	9	9	9	9
Skoda		15	8	13	9	10
Honda		10	11	10	11	10;

end;
