/*
 ============================================================================
 Name        : sueldo-pepe.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

int main(void) {
	t_persona *pepe = persona_init(CATEGORIA_CADETE, BONO_RESULTADOS_FIJO, BONO_PRESENTISMO_FALTAS);
	persona_faltas(pepe, 3);
	printf("Cadete con resultados fijo y presentismo con 3 faltas: %s\n", persona_sueldo(pepe) == 15080 ? "OK" : "FAIL");
	persona_destroy(pepe);

	pepe = persona_init(CATEGORIA_GERENTE, BONO_RESULTADOS_PORCENTAJE, BONO_PRESENTISMO_FIJO);
	printf("Gerente con resultados a porcentaje y presentismo fijo: %s\n", persona_sueldo(pepe) == 11000 ? "OK" : "FAIL");
	persona_destroy(pepe);

	pepe = persona_init(CATEGORIA_CADETE, BONO_RESULTADOS_PORCENTAJE, BONO_PRESENTISMO_FALTAS);
	printf("Cadete con resultados a porcentaje y presentismo sin faltas: %s\n", persona_sueldo(pepe) == 16600 ? "OK" : "FAIL");
	persona_destroy(pepe);

	pepe = persona_init(CATEGORIA_CADETE, BONO_RESULTADOS_PORCENTAJE, BONO_PRESENTISMO_FALTAS);
	persona_faltas(pepe, 1);
	printf("Cadete con resultados a porcentaje y presentismo con 1 falta: %s\n", persona_sueldo(pepe) == 16550 ? "OK" : "FAIL");
	persona_destroy(pepe);

	return EXIT_SUCCESS;
}
