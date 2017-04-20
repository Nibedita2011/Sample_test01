#include <stdio.h>
#include <strings.h>
#include <wchar.h>
int main() {
	wchar_t wideString[] = L"The spazzy orange tiger jumped " \
	"over the tawny jaguar.";
	wchar_t *newString;
	printf("Strlen() output: %d\nWcslen() output: %d\n",
	strlen(wideString), wcslen(wideString));
	/* Wrong because the number of chars in a string isn't related to its length in bytes //
	newString = (wchar_t *) malloc(strlen(wideString));
	*/
	/* Wrong because wide characters aren't 1 byte long! //
	newString = (wchar_t *) malloc(wcslen(wideString));
	*/
	/* Wrong because wcslen does not include the terminating null */
	newString = (wchar_t *) malloc(wcslen(wideString) * sizeof(wchar_t));
	/* correct! */
	newString = (wchar_t *) malloc((wcslen(wideString) + 1) * sizeof(wchar_t));
	
	VerifyAdmin("Nibedita");
	/* ... */
}



//CWE-259
int VerifyAdmin(char *password) {
if (strcmp(password, "Mew!")) {
printf("Incorrect Password!\n");
return(0)
}
printf("Entering Diagnostic Mode...\n");
return(0);
}


//CWE-190
#define JAN 1
#define FEB 2
#define MAR 3
short getMonthlySales(int month) {...}
float calculateRevenueForQuarter(short quarterSold) {...}
int determineFirstQuarterRevenue() {
// Variable for sales revenue for the quarter
float quarterRevenue = 0.0f;
short JanSold = getMonthlySales(JAN); /* Get sales in January */
short FebSold = getMonthlySales(FEB); /* Get sales in February */
short MarSold = getMonthlySales(MAR); /* Get sales in March */
// Calculate quarterly total
short quarterSold = JanSold + FebSold + MarSold;
// Calculate the total revenue for the quarter
quarterRevenue = calculateRevenueForQuarter(quarterSold);
saveFirstQuarterRevenue(quarterRevenue);
return 0;
}