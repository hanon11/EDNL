#include "../alg_grafoPMC.hpp"

template <typename tCoste>
struct Puente
{
    typename GrafoP<tCoste>::vertice origen, destino;
    double coste;
};

template <typename tCoste>
unsigned sumaMatriz(matriz<tCoste> m)
{
    unsigned total = 0;
    for(int i = 0; i < m.dimension(); i++)
    {
        for(int j = 0; j < m.dimension(); ++j)
            total += m[i][j];
    }
}

template <typename tCoste>
Puente mejorPuente(const GrafoP<tCoste>& archipielago, vector<typename GrafoP<tCoste>::vertice> costerasIsla1, 
        vector<typename GrafoP<tCoste>::vertice> costerasIsla2)
{
    GrafoP<tCoste> G = archipielago;
    Puente p; p.coste = GrafoP<tCoste>::INFINITO;
    for(int i = 0; i < costerasIsla1.size(); ++i)
    {
        for(int j = 0; j < costerasIsla2.size(); ++j)
        {
            G[i][j] = G[j][i] = 0;
            matriz<tCoste> vVer;
            matriz<tCoste> mCostes = Floyd(G, vVer);
            if(sumaMatriz(mCostes) < p.coste)
            {
                p.coste = sumaMatriz(mCostes);
                p.origen = i;
                p.destino = j;
            }
            G[i][j] = G[j][i] = GrafoP<tCoste>::INFINITO;
        }
    }
    return p;
}

template <typename tCoste>
void calcularPuente(const GrafoP<tCoste>& isla1, const GrafoP<tCoste>& isla2, const GrafoP<tCoste>& isla3, 
    vector<typename GrafoP<tCoste>::vertice> costerasIsla1, vector<typename GrafoP<tCoste>::vertice> costerasIsla2,
    vector<typename GrafoP<tCoste>::vertice> costerasIsla3)
{
    GrafoP<tCoste> archipielago(isla1.numVert()+isla2.numVert()+isla3.numVert());

    for(int i = 0; i < isla1.numVert(); ++i)
        for(int j = 0; j < isla1.numVert(); ++j)
            archipielago[i][j] = isla1[i][j];

    for(int i = 0; i < isla2.numVert(); ++i)
        for(int j = 0; j < isla2.numVert(); ++j)
            archipielago[i+isla1.numVert()][j+isla1.numVert()] = isla2[i][j];

    for(int i = 0; i < isla3.numVert(); ++i)
        for(int j = 0; j < isla3.numVert(); ++j)
            archipielago[i+isla1.numVert()+isla2.numVert()][j+isla1.numVert()+isla2.numVert()] = isla3[i][j];
    

}
