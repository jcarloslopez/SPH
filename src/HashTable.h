
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Particle.h"

class HashTable
{
	public:
    	HashTable(unsigned num_particulas, float tam_celda);
		int insertar(ofVec3f c, int p);
		unsigned hash(const ofVec3f c);
		void limpiar();
		int size();
		vector<vector<int>> getTabla();
		vector<int> getVecinos(ofVec3f c);

	private:
		vector<vector<int>> t;
		float cell_size;
		int tam;
};

#endif
