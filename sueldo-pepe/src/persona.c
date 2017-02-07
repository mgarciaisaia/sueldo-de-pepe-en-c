/*
 * persona.c
 *
 *  Created on: 7/2/2017
 *      Author: utnso
 */
#include "persona.h"
#include <stdlib.h>
#include <stdio.h>

t_persona *persona_init(t_categoria categoria, t_bono_resultados bono_resultados, t_bono_presentismo bono_presentismo) {
	t_persona *self = malloc(sizeof(t_persona));
	self->faltas = 0;
	self->categoria = categoria;
	self->bono_resultados = bono_resultados;
	self->bono_presentismo = bono_presentismo;
	return self;
}

void persona_destroy(t_persona *self) {
	free(self);
}

void persona_faltas(t_persona *self, int faltas) {
	self->faltas = faltas;
}

int sueldo_neto(t_persona *self) {
	switch(self->categoria) {
	case CATEGORIA_GERENTE:
		return 10000;
		break;
	case CATEGORIA_CADETE:
		return 15000;
		break;
	default:
		printf("ERROR: Categoria no implementada: %d\n", self->categoria);
		return 0;
	}
}

int bono_presentismo(t_persona *self) {
	switch(self->bono_presentismo) {
	case BONO_PRESENTISMO_FIJO:
		return 0;
		break;
	case BONO_PRESENTISMO_FALTAS:
		if(self->faltas == 0) {
			return 100;
		}
		if(self->faltas == 1) {
			return 50;
		}
		return 0;
		break;
	default:
		printf("ERROR: Bono presentismo no implementado: %d\n", self->bono_presentismo);
		return 0;
	}
}

int bono_resultados(t_persona *self) {
	switch(self->bono_resultados) {
	case BONO_RESULTADOS_NULO:
		return 0;
		break;
	case BONO_RESULTADOS_FIJO:
		return 80;
		break;
	case BONO_RESULTADOS_PORCENTAJE:
		return sueldo_neto(self) * 0.1;
		break;
	default:
		printf("ERROR: Bono resultados no implementado: %d\n", self->bono_resultados);
		return 0;
	}
}

int persona_sueldo(t_persona *self) {
	return sueldo_neto(self) + bono_presentismo(self) + bono_resultados(self);
}
