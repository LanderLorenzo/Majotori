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
    bool* respuestas;
public:
    virtual ~historiaRecorrida();
    historiaRecorrida(bool* respuestas, char* fichero);
    historiaRecorrida(historiaRecorrida& hr);
    bool tombola();
    void setRespuestas(bool respuestas[10]);
    bool* getRespuestas();

};


#endif /* HISTORIA_H_ */
