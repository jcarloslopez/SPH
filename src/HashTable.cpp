#include "HashTable.h"

HashTable::HashTable(unsigned _tam, float tam_celda){
	tam = _tam;
	cell_size = tam_celda;
	t = vector<vector<int>>( tam );
	
}

int HashTable::insertar(ofVec3f c, int p){
	int pos;
	pos=hash(c);
	t[pos].push_back(p);
	return pos;
}

unsigned HashTable::hash(const ofVec3f c){
	int xd=(int)floor((double)c.x/cell_size);
	int yd=(int)floor((double)c.y/cell_size);
	int zd=(int)floor((double)c.z/cell_size);
	return(73856093*xd+19349663*yd+83492791*zd)%t.size();
}

void HashTable::limpiar(){
	for(int i = 0; i < t.size(); i++){
		t[i].clear();
	}
}

int HashTable::size(){
	return tam;
}

vector<vector<int>> HashTable::getTabla(){
	return t;
}

vector<int> HashTable::getVecinos(ofVec3f c){
	vector<int> vecinos;
	ofVec3f p;
	
	for (int i = -1; i < 2; i++){
		for (int j = -1; j < 2; j++){
			for (int k = -1; k < 2; k++){
				p = c;
				p.x += cell_size*i;
				p.y += cell_size*j;
				p.z += cell_size*k;
				
				vecinos.insert(vecinos.end(),t[hash(p)].begin(),t[hash(p)].end());
			}
		}
	}

	return vecinos;
}
