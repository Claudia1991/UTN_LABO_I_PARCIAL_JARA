#include "Reports.h"

void ShowClientWithMoreActiveLoans(eLoan loanArray[], int sizeLoan,
		eClient clientArray[], int sizeClient) {
	if (clientArray != NULL && loanArray != NULL && sizeClient > 0
			&& sizeLoan > 0) {
		int idClient;
		int index;
		printf(
				"********** INICIO REPORTE CLIENTE CON MAS PRESTAMOS ACTIVOS **********\n");
		if (!IsEmptyClientArray(clientArray, sizeClient)) {
			idClient = GetClientIdWihtMoreLoansByState(clientArray, sizeClient,
					loanArray, sizeLoan, 1);
			index = FindClientById(clientArray, sizeClient, idClient);
			ShowClient(clientArray[index]);
		} else {
			printf(":::[LA LISTA DE CLIENTES ESTA VACIA]:::\n");
		}
		printf(
				"********** FIN REPORTE CLIENTE CON MAS PRESTAMOS ACTIVOS **********\n");
	}
}
void ShowClientWithMorePayedLoans(eLoan loanArray[], int sizeLoan,
		eClient clientArray[], int sizeClient) {
	if (clientArray != NULL && loanArray != NULL && sizeClient > 0
			&& sizeLoan > 0) {
		int idClient;
		int index;
		printf(
				"********** INICIO REPORTE CLIENTE CON MAS PRESTAMOS SALDADOS **********\n");
		if(!IsEmptyClientArray(clientArray, sizeClient)){
			idClient = GetClientIdWihtMoreLoansByState(clientArray, sizeClient,
							loanArray, sizeLoan, 0);
					index = FindClientById(clientArray, sizeClient, idClient);
					ShowClient(clientArray[index]);
		}else{
			printf(":::[LA LISTA DE CLIENTES ESTA VACIA]:::\n");
		}
		printf(
				"********** FIN REPORTE CLIENTE CON MAS PRESTAMOS SALDADOS **********\n");
	}
}

void ShowLoansUpperDefaultMin(eLoan loanArray[], int sizeLoan) {
	if (loanArray != NULL && sizeLoan > 0) {
		printf(
				"********** INICIO REPORTE PRESTAMOS MAYORES A 1000 **********\n");
		if (!IsEmptyLoanArray(loanArray, sizeLoan)) {
			int quantity = QuantityLoansUpper(loanArray, sizeLoan, 1, 0);
			printf("Prestamos mayores a 1000: [%d]\n", quantity);
		} else {
			printf(":::[LA LISTA DE PRESTAMOS ESTA VACIA]:::\n");
		}
		printf("********** FIN REPORTE PRESTAMOS MAYORES A 1000 **********\n");
	}
}
void ShowLoansUpperByAmount(eLoan loanArray[], int sizeLoan) {
	if (loanArray != NULL && sizeLoan > 0) {
		int quantity;
		float amount;
		printf(
				"********** INICIO REPORTE PRESTAMOS MAYORES A UN MONTO **********\n");
		if (!IsEmptyLoanArray(loanArray, sizeLoan)) {
			GetFloatNumberNoMinMax(&amount,
					"Ingrese el monto para realizar el reporte: ",
					"ERROR: ingrese numeros correctamente\n", RETRIES);
			quantity = QuantityLoansUpper(loanArray, sizeLoan, 0, amount);
			printf("Prestamos iguales a [%2f]: [%d]\n", amount, quantity);
		} else {
			printf(":::[LA LISTA DE PRESTAMOS ESTA VACIA]:::\n");
		}
		printf(
				"********** FIN REPORTE PRESTAMOS MAYORES A UN MONTO **********\n");
	}
}

