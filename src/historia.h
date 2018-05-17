/*
 * historia.h
 *
 *  Created on: 17 may. 2018
 *      Author: Lander
 */

#ifndef HISTORIA_H_
#define HISTORIA_H_

class historia{

protected:
	char* texto;
public:
	historia();
	virtual ~historia();
	historia(char* texto);
	historia(const historia&);
	void setTexto(char*);
	char* getTexto();
	void mostrarTexto();
};

class historiaRamificada: public historia{

private:
	bool respuestas[10];
public:
	historiaRamificada();
	virtual ~historiaRamificada();
	historiaRamificada(bool respuestas[]);
	historiaRamificada(historiaRamificada& hr);
	bool tombola();
	void setRespuestas(bool respuestas[]);
	bool* getRespuestas();
};

#endif /* HISTORIA_H_ */
