/*
 * persona.h
 *
 *  Created on: 7/2/2017
 *      Author: utnso
 */

#ifndef PERSONA_H_
#define PERSONA_H_

typedef enum { CATEGORIA_GERENTE, CATEGORIA_CADETE } t_categoria;
typedef enum { BONO_RESULTADOS_FIJO, BONO_RESULTADOS_PORCENTAJE, BONO_RESULTADOS_NULO } t_bono_resultados;
typedef enum { BONO_PRESENTISMO_FALTAS, BONO_PRESENTISMO_FIJO } t_bono_presentismo;

typedef struct {
	int faltas;
	t_categoria categoria;
	t_bono_resultados bono_resultados;
	t_bono_presentismo bono_presentismo;
} t_persona;

t_persona *persona_init(t_categoria categoria, t_bono_resultados bono_resultados, t_bono_presentismo bono_presentismo);
void persona_destroy(t_persona *self);

void persona_faltas(t_persona *self, int faltas);
int persona_sueldo(t_persona *self);

#endif /* PERSONA_H_ */
