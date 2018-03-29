/*
UFPB - CENTRO DE INFORMATICA
DISCIPLINA: ANÁLISE E PROJETO DE ALGORITMOS
AUTOR: BRUNO CORREIA
DATA: 14/03/2018
VERSÃO: 0.001
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

// CLASSE MENSAGEM
class mensagem{
public:

	void versao(){
		cout<<"Versão 0.001"<<endl<<endl;
	}

	void ajuda(){
		cout<<"\nUso: ./ordenacao4 [OPÇÕES]\n\nOPÇÕES:\n\n -t [cs|rs]     Tipo da Ordenação. P/ CountingSort -> CS , RadixSort -> RS.\n\n                        Ex.: -t cs | -t rs\n\n -i [Arquivo]   Define o arquivo de entrada, com os valores a serem ordenados.\n\n                        Ex.: -i ./couting.txt | -i ~/ordenar.txt\n\n\n -h      Mostra esta tela de ajuda e sai\n -v      Mostra a versão do programa e sai\n\n\nExemplo completo de uso:\n\n./ordenacao4 -t cs -i entrada.txt\n\n";
	}

	void erro(){
		cout<<"Opção inválida, tente novamente. Use -h para ajuda."<<endl<<endl;
    }
    
};

/* COUTINGSORT - INICIO */

void CountingSort(int array[], int tam, int maior){

	int arrayOrdenado[tam];
	int arrayAux[maior + 1] = {0};

	// CONTANDO O N DE OCORRENCIAS DE CADA ELEMENTO DO VETOR
	// E GUARDA EM UM VETOR AUXILIAR USANDO O ELEMENTO COMO INDICE
	for (int i = 0; i < tam; i++){
		arrayAux[array[i]] += 1;
	}

	//exibeArray(arrayAux,sizeof(arrayAux)/sizeof(int));

	// FAZ A SOMA PARA SABER O QUANTO E NECESSARIO
	// DESLOCAR PARA GUARDAR CADA ELEMENTO
	for (int j = 1; j <= maior; j++){
		arrayAux[j] += arrayAux[j-1];
	}

	//exibeArray(arrayAux,sizeof(arrayAux)/sizeof(int));

	// COLOCAR ELEMENTOS NAS POSICOES CORRETAS
	for (int l = (tam-1) ; l >= 0 ; l-- ){
		arrayOrdenado[ (arrayAux[array[l]]) -1 ] = array[l];
		arrayAux[array[l]] -= 1;
	}

	//exibeArray(arrayOrdenado,sizeof(arrayOrdenado)/sizeof(int));

	// PASSA ELEMENTOS DO VETOR ORDENADO PARA VETOR ORIGINAL EM SUAS
	// POSICOES CORRETAS
	while(tam--){
		array[tam] = arrayOrdenado[tam];
	}

}

/* COUTINGSORT - FIM */

/* RADIXSORT - INICIO */

void contar(int array[], int n, int exp)
{
    int arraySaida[n];
    int i, count[10] = {0};
 
    for (i = 0; i < n; i++)
        count[ (array[i]/exp)%10 ]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--)
    {
        arraySaida[count[ (array[i]/exp)%10 ] - 1] = array[i];
        count[ (array[i]/exp)%10 ]--;
    }
 
    for (i = 0; i < n; i++)
        array[i] = arraySaida[i];
}

void RadixSort(int array[], int tam, int maior){

    for (int exp = 1; maior/exp > 0; exp *= 10){
        contar(array, tam, exp);
    }
}

/* RADIXSORT - FIM */


int main(int argc, char *argv[]){

	mensagem exibir;

	int i, numParametros = argc;

	string	nomePrograma=argv[0], tipo, arquivoEntrada, arquivoSaida;


	if ( numParametros == 2 ){

		if (argv[1][0] == '-' ){

			switch(argv[1][1]){

				case 'v':
				case 'V':
					exibir.versao();
					return 0;
					break;

				case 'h':
				case 'H':
					exibir.ajuda();
					return 0;
					break;

				default:
					exibir.erro();
					return 1;
			}

		}

	} else if ( numParametros == 5 ){

			while ((++argv)[0]){

				if (argv[0][0] == '-' ){

					switch(argv[0][1]){

						case 't':
							tipo = argv[1];
							break;

						case 'i':
							arquivoEntrada = argv[1];
							break;

						default:
							exibir.erro();
							return 1;
					}

				}

			}

		// EXECUTION PROGRAM
		ifstream contar(arquivoEntrada.c_str());

		int N_LINHAS = 0;
		int maiorElemento=0;

		if(!contar.is_open()){
			cout << "Arquivo não pode ser aberto, verifique se o mesmo existe." << "\n\n";
			return 1;
		} else {
			string linha;

			while(getline(contar,linha)){
				++N_LINHAS;
			}

			contar.close();
		}

		int array[N_LINHAS];

		ifstream arquivo(arquivoEntrada.c_str());

		if(!arquivo.is_open()){
			cout << "Arquivo não pode ser aberto, verifique se o mesmo existe." << "\n\n";
			return 1;
		}

		for( i=0 ; i < N_LINHAS ; i++ ){
			arquivo >> array[i];
		}

		arquivo.close();

		if ( tipo == "CS" || tipo == "cs" ) {
			
		    cout << endl << "Couting Sort" << endl << endl;
		    cout << "Antes de ordenar:" << endl;

		    for (int i = 0;i < N_LINHAS; i++)
		        cout << array[i] << " ";

		    cout << endl;

		    // PEGA O MAIOR ELEMENTO
		    for (int n=0; n < N_LINHAS; n++){

				if (array[n] > maiorElemento){
					maiorElemento = array[n];
				}

			}

			// ORDENA COM COUTING SORT
			CountingSort(array, N_LINHAS, maiorElemento);

		    cout << endl << "Depois de ordenar:" << endl;
		    for (int i = 0; i < N_LINHAS; i++)
		        cout << array[i] << " ";
		    
		    cout << endl << endl;
		    

		} else if ( tipo == "RS" || tipo == "rs" ){
			
		    cout << endl << "Radix Sort" << endl << endl;
		    cout << "Antes de ordenar:" << endl;

		    for (int i = 0; i < N_LINHAS; i++){
		        cout << array[i] << " ";
		    }

		    
		    // PEGA MAIOR ELEMENTO
		    for (int n=0; n < N_LINHAS; n++){

				if (array[n] > maiorElemento){
					maiorElemento = array[n];
				}

			}
			

			// ORDENA COM RADIX SORT
		    RadixSort(array, N_LINHAS, maiorElemento);

		    cout << endl << endl << "Depois de ordenar:" << endl;
		    for (int i = 0;i < N_LINHAS; i++)
		        cout << array[i] << " ";
		    cout << endl << endl;

		} else {

			cout << "Tipo inválido, use" << nomePrograma << " -h para ajuda." << "\n\n";
			return 1;

		}

	} else {

		exibir.erro();
		return 1;
	
	}

	return 0;

}