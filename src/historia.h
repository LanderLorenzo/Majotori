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
	historia(char* fichero);
	historia(const historia&);
	void setTexto(char*);
	char* getTexto();
	void mostrarTexto();
};

class historiaRecorrida: public historia{

private:
    bool respuestas[10];
    int rama;
public:
    historiaRecorrida();
    virtual ~historiaRecorrida();
    historiaRecorrida(bool respuestas[], char* fichero,int rama);
    historiaRecorrida(historiaRecorrida& hr);
    bool tombola();
    void setRespuestas(bool respuestas[]);
    bool* getRespuestas();

};

#endif /* HISTORIA_H_ */
