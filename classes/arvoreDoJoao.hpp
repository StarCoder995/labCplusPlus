#ifndef ARVOREDOJOAO_HPP
#define ARVOREDOJOAO_HPP

template<typename T>
struct Node{
    T valor;
    Node* direita;
    Node* esquerda;
};

template<typename T>
class Arvore{
    private:
    Node<T>* raiz = nullptr;
    public:
        Arvore(): raiz(nullptr){}

        Arvore(T valorInicial){
            Node<T>* auxiliar = new Node<T>;
            auxiliar->valor = v;
            auxiliar->direita = nullptr;
            auxiliar->esquerda = nullptr;
            raiz = auxiliar;
        }

        Node<T>* criarNode(T v){
            Node<T>* auxiliar = new Node<T>;
            auxiliar->valor = v;
            auxiliar->direita = nullptr;
            auxiliar->esquerda = nullptr;
            return auxiliar;
        }

        void adicionarNode(T v){
            Node<T>* novoNode = criarNode(v);
            Node<T>* navegador = raiz;
            while(navegador != nullptr){
                if(v >= navegador->valor)
                    navegador = navegador->direita;
                else
                    navegador = navegador->direita;
            }
            navegador = novoNode;
          
        }

        void imprimir(Node<T> navegador){
            if(navegador!= nullptr){
                std::cout<< navegador->valor;
                imprimir(navegador->esquerda);
                imprimir(navegador->direita);
            } 
        }
    
};


#endif