/**
 *@file MyIterator.h
 *@author Társila Samille (tarsillasamile@gmail.com)
 *@brief
 *@version 0.1
 *@date 2020-11-25
 * @section DESCRIÇÃO
 *Implementação da tabela de dispersão.
 *@copyright Copyright (c) 2020
 *
 */
#ifndef HASHTBL_H
#define HASHTBL_H
#include <iostream>
#include <forward_list>
#include <exception>

namespace ac
{

	template < class KeyType, class DataType>
		class HashEntry
		{
			public:

				KeyType m_key;	// Armazena a chave associada a informcao
                DataType m_data;	// A informacao.

                HashEntry(KeyType kt_, DataType dt_): m_key(kt_), m_data(dt_)
                { 	/*Empty*/
                }
		};

	template < class KeyType, class DataType, typename KeyHash = std::hash < KeyType>, typename KeyEqual = std::equal_to < KeyType>>
		class HashTbl
		{
			public:
				using Entry = HashEntry<KeyType, DataType> ;
                using list_type = std::forward_list<Entry> ;
                using size_type = std::size_t;

                KeyHash hashFunctor;	//!< Instacia o functor para primary hash.
                KeyEqual equalFunctor;	//!< Instacia o functor para equal for test.

			/**
			 *@brief Construtor que aloca dinamicamente em *m_data_table um
			 *vetor cujo tamanho é determinado como sendo o menor número primo ≥ que o valor especificado em tbl_size .
			 *Esta é a área de armazenamento dos dados, ou seja, cada elemento
			 *deste vetor é um ponteiro para uma lista de itens de tabela, ou HashEntry .
			 *@param tbl_size
			 */
			explicit HashTbl(int tbl_size = DEFAULT_SIZE): m_size(tbl_size), m_count(0)
			{
				m_size = proxPrimo(m_size);
				m_count = 0;
				m_data_table = new list_type[m_size];
			}
			/**
			 *@brief : Destruidor da classe que libera a memória apontada por m_data_table .
			 *Antes de liberar a memória, percorre o vetor liberando a memória utilizada por
			 *cada lista de colisão.
			 *
			 */
			HashTbl(const HashTbl &other)
			{
				m_size = other.m_size;
				m_count = other.m_count;
				m_data_table = new list_type[m_size];

				for (unsigned int i = 0; i < m_size; i++)
					m_data_table[i] = other.m_data_table[i];
			}
			/**
			 *@brief Constroi uma nova Hash Tbl a partir de uma lista
			 *
			 *@param ilist
			 */

			HashTbl(std::initializer_list<Entry> ilist)
			{
				m_size = ilist.size();
				m_count = 0;
				m_data_table = new list_type[m_size];

				for (auto it = ilist.begin(); it != ilist.end(); ++it)
					insert(it->m_key, it->m_data);
			}
			/**
			 *@brief
			 *
			 *@param other
			 *@return HashTbl&
			 */
			HashTbl &operator=(const HashTbl &other)
			{
				clear();
				delete[] m_data_table;

				m_size = other.m_size;
				m_count = other.m_count;
				m_data_table = new list_type[m_size];

				for (unsigned int i = 0; i < m_size; i++)
					m_data_table[i] = other.m_data_table[i];

				return * this;
			}
			/**
			 *@brief
			 *
			 *@param ilist
			 *@return HashTbl&
			 */
			HashTbl &operator=(std::initializer_list<Entry> ilist)
			{
				delete[] m_data_table;

				m_size = ilist.size();
				m_count = 0;
				m_data_table = new list_type[m_size];

				for (auto it = ilist.begin(); it != ilist.end(); ++it)
					insert(it->m_key, it->m_data);

				return * this;
			}
			/**
			 *@brief Destroi o virtual object Hash Tbl
			 *
			 */
			virtual~HashTbl()
			{
				delete[] m_data_table;
			}

			/**
			 *@brief Insere na tabela a informação contida em data e associada a uma chave key .
			 *Calcula o endereço end que a informação data deve ocupar na tabela e o armazena na
			 *lista de colisão correspondente, ou seja, em m_data_table[end] .
			 *
			 *@param key
			 *@param data
			 *@return true - a inserção foi realizada com sucesso
			 *@return false - a chave já existe na tabela, sobrescreve
			 *os dados da tabela com os dados contidos em data, para diferençar de uma
			 *inserção realizada pela primeira vez.
			 */
			bool insert(const KeyType &key, const DataType &data)
			{

				auto end = hashFunctor(key) % m_size;
				Entry new_entry(key, data);

				for (auto it = m_data_table[end].begin(); it != m_data_table[end].end(); it++)
				{
					if (equalFunctor(it->m_key, new_entry.m_key))
					{
						it->m_data = data;
						return false;
					}
				}

				m_count++;
				m_data_table[end].push_front(new_entry);

				return true;
			}
			/**
			 *@brief  Remove um item de tabela identificado por sua chave key .
			 *
			 *@param key
			 *@return true - a chave foi encontrada
			 *@return false  - a chave não foi encontrada
			 */
			bool erase(const KeyType &key)
			{

				auto end(hashFunctor(key) % m_size);

				auto pos = m_data_table[end];
				auto inicio = pos.begin();
				auto fim = pos.end();

				auto anterior = pos.before_begin();

				for (auto it { inicio }; it != fim; ++it)
				{
					if (equalFunctor(it->m_key, key))
					{
						pos.erase_after(anterior);
						m_count--;
						m_data_table[end] = pos;
						return true;
					}
					anterior++;
				}

				return false;
			}

			/**
			 *@brief Recupera em data a informação associada a chave key passada como
			 *argumento para o método.
			 *
			 *@param key
			 *@param data
			 *@return true - a chave foi encontrada
			 *@return false  - a chave não foi encontrada
			 */
			bool retrieve(const KeyType &key, DataType &data) const
			{

				auto end(hashFunctor(key) % m_size);	

				for (auto it = m_data_table[end].begin(); it != m_data_table[end].end(); it++)
				{
					if (equalFunctor(it->m_key, key))
					{
						data = it->m_data;
						return true;
					}
				}

				return false;
			}

			/**
			 *@brief  Limpa (apaga) toda a memória associada às listas de colisão da tabela, removendo
			 *todos seus elementos.
			 *
			 */
			void clear(void)
			{
				for (unsigned int i { 0 }; i < m_size; i++)
					m_data_table[i].clear();

				m_count = 0;
			}

			/**
			 *
			 *@return true - a tabela de dispersão está vazia
			 *@return false - a tabela de dispersão não está vazia
			 */

			bool empty(void) const
			{
				if (this->m_count == 0)
					return true;

				return false;
			}

			/**
			 *@brief : Retorna a quantidade de elementos atualmente armazenados na tabela.
			 *
			 *@return size_type
			 */
			inline size_type size(void) const
			{
				return this->m_count;
			}

			/**
			 *@brief  Retorna uma referência para o dado associado a chave key fornecida, se
			 *existir. Se a chave não estiver na tabela, o método realizar a inserção e retorna a referência
			 *para o dado recém inserido na tabela.
			 *
			 *@param key
			 *@return DataType&
			 */
			DataType &operator[](const KeyType &key)
			{

				auto end(hashFunctor(key) % m_size);

				for (auto &e: m_data_table[end])
				{
					if (equalFunctor(e.m_key, key) == true)
						return e.m_data;
				}

				DataType dt = DataType();
				Entry entry(key, dt);

				m_count++;
				m_data_table[end].push_front(entry);

				return m_data_table[end].front().m_data;
			}

			/**
			 *@brief : Retorna uma referência para o dado associado a chave key fornecida. Se a chave não
			 *estiver na tabela, o método lança uma exceção do tipo std::out_of_range .
			 *
			 *@param key
			 *@return DataType&
			 */
			DataType &at(const KeyType &key)
			{
                auto end(hashFunctor(key) % m_size);
                auto inicio = m_data_table[end].begin();
                auto fim = m_data_table[end].end();

				for (auto it(inicio); it != fim; it++)
				{
					if (equalFunctor(it->m_key, key))
					{
						return it->m_data;
					}
				}
				throw std::out_of_range("Chave não encontrada.");
			}

			/**
			 *@brief Retorna a quantidade de elementos da tabela que estão na lista de colisão associada
			 *a chave key .
			 *
			 *@param key
			 *@return size_type
			 */
			size_type count(const KeyType &key) const
			{
				KeyHash hashFunctor;

				size_type cont = 0;
				auto end(hashFunctor(key) % m_size);

				auto inicio = m_data_table[end].begin();
				auto fim = m_data_table[end].end();

				for (auto it(inicio); it != fim; it++)
				{
					cont++;
				}

				return cont;
			}

			/**
			 *@brief : E um método de  depuração usado para gerar uma representação
			 *textual da tabela e seus elementos.
			 *
			 *@param os
			 *@param hash
			 *@return std::ostream&
			 */
			friend std::ostream &operator<<(std::ostream &os, const HashTbl &hash)
			{
				for (unsigned int i { 0 }; i < hash.m_size; i++)
				{
					auto inicio = hash.m_data_table[i].begin();
					auto fim = hash.m_data_table[i].end();

					os << "[" << i << "]";

					for (auto it { inicio }; it != fim; it++)
						os << "  " << it->m_data;

					os << std::endl;
				}

				return os;
			}

			//=== Private methods
			private:
				/**
				 *@brief E um método  privado que deve ser chamado quando o fator de carga λ for maior
				 *que 1.0. O fator de carga é a razão entre o número de elementos na tabela e seu tamanho.
				 *Este método vai criar uma nova tabela cujo tamanho será igual ao menor número primo
				 *que o dobro do tamanho da tabela antes da chamada rehash() . Após a criação da nova
				 *tabela, todos os elementos devem ser inseridos na nova tabela, de acordo com uma nova
				 *função de dispersão secundária, baseada no novo tamanho da tabela. Cuidado especial deve
				 *ser tomado para evitar vazamento de memória. O cliente não deve perceber que esta operação foi acionada.
				 *
				 */
				void rehash()
				{
					list_type old_m_data_table = m_data_table;
					m_size = proxPrimo(m_size *2);
					m_data_table.resize(m_size);
					m_count = 0;
					for (auto &this_list: m_data_table)
						this_list.clear();
					for (auto &copy_m_data_table: old_m_data_table)
						for (auto &x: copy_m_data_table)
							insert(x.m_key, x.m_data);
				}
			/**
			 *@brief retorna o proximo primo depois de num ou o DEFAULT_SIZE se o numero for menor que o DEFAULT_SIZE;
			 *
			 *@param num
			 *@return int
			 */
			int proxPrimo(int num)
			{
				if (num <= DEFAULT_SIZE) return DEFAULT_SIZE;
				for (int i = 2; i < num; i++)
				{
					if (num % i == 0)
						return proxPrimo(num++);
				}
				return num;
			}
			//=== Private memnbers
			private:
				unsigned int m_size;	//!< Tamanho da tabela.
                unsigned int m_count;	//!< Numero de elementos na tabel.
                list_type * m_data_table;	//!< Tabela de listas para entradas de tabela.
                // std::unique_ptr<std::forward_list < Entry>[] > m_data_table;
                static const short DEFAULT_SIZE = 11;
		};
};	// namespace ac

#endif