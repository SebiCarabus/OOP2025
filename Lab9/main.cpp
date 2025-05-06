#include <iostream>

using namespace std;

template<class K, class V>
class Map
{
private:
	K* chei;
	V* valori;
	unsigned int nr;
public:
	Map<K, V>()
	{
		this->chei = nullptr;
		this->valori = nullptr;
		this->nr = 0;
	}

	Map<K, V>(const Map<K, V>& x)
	{
		if (this->chei != nullptr)
		{
			delete[]this->chei;
			delete[]this->valori;
		}
		this->chei = new K[x.nr];
		this->chei = x.chei;
		this->valori = new V[x.nr];
		this->valori = x.valori;
		this->nr = x.nr;
	}

	Map<K, V>(Map<K, V>&& x)
	{
		if (this->chei != nullptr)
		{
			delete[]this->chei;
			delete[]this->valori;
		}
		this->chei = new K[x.nr];
		this->chei = x.chei;
		this->valori = new V[x.nr];
		this->valori = x.valori;
		this->nr = x.nr;
		x.chei = nullptr;
		x.valori = nullptr;
	}

	~Map<K, V>()
	{
		if (this->chei != nullptr)
		{
			delete[]this->chei;
			delete[]this->valori;
		}
	}

	V& operator[](const K index)
	{
		unsigned int i, j;
		for (i = 0;i < this->nr;i++)
			if (this->chei[i] == index)
				return this->valori[i];
		K* n_chei = new K[this->nr + 1];
		for (j = 0;j < this->nr;j++)
			n_chei[j] = this->chei[j];
		n_chei[this->nr] = index;
		V* n_valori = new V[this->nr + 1];
		for (j = 0;j < this->nr;j++)
			n_valori[j] = this->valori[j];
		n_valori[this->nr] = 0;
		delete[]this->valori;
		delete[]this->chei;
		this->valori = n_valori;
		this->chei = n_chei;
		this->nr++;
		return this->valori[this->nr - 1];
	}

	void Set(const K index, const V val)
	{
		unsigned int i,j;
		for (i = 0;i < this->nr;i++)
			if (this->chei[i] == index)
			{
				this->valori[i] = val;
				return;
			}
		K* n_chei = new K[this->nr + 1];
		for (j = 0;j < this->nr;j++)
			n_chei[j] = this->chei[j];
		n_chei[this->nr] = index;
		V* n_valori = new V[this->nr + 1];
		for (j = 0;j < this->nr;j++)
			n_valori[j] = this->valori[j];
		n_valori[this->nr] = val;
		delete[]this->valori;
		delete[]this->chei;
		this->valori = n_valori;
		this->chei = n_chei;
		this->nr++;
	}
	bool Get(const K& key, V& value)
	{
		unsigned int i;
		for (i = 0;i < this->nr;i++)
			if (this->chei[i] == key)
			{
				value = this->valori[i];
				return true;
			}
		return false;
	}
	unsigned int Count()
	{
		return this->nr;
	}
	void Clear()
	{
		if (this->chei != nullptr)
		{
			delete[]this->chei;
			this->chei = nullptr;
			delete[]this->valori;
			this->valori = nullptr;
		}
		this->nr = 0;
	}

	void Delete(const K key)
	{
		unsigned int i, k;
		bool ok = false;
		for (i = 0;ok == false && i < this->nr;i++)
			if (this->chei[i] == key)
			{
				k = i;
				ok = true;
			}
		if (ok == false)
			return;
		K* n_chei = new K[this->nr - 1];
		V* n_valori = new V[this->nr - 1];
		for (i = 0;i < k;i++)
		{
			n_chei[i] = this->chei[i];
			n_valori[i] = this->valori[i];
		}
		for (i = k;i < this->nr - 1;i++)
		{
			n_chei[i] = this->chei[i + 1];
			n_valori[i] = this->valori[i + 1];
		}
		delete[]this->chei;
		delete[]this->valori;
		this->chei = n_chei;
		this->valori = n_valori;
		this->nr--;
	}
	bool Includes(const Map<K, V>& map)
	{
		unsigned int i, j, nr_este = 0;
		for (j = 0;j < map.nr;j++)
			for (i = 0;i < this->nr;i++)
				if (this->chei[i] == map.chei[j])
					nr_este++;
		return(nr_este == map.nr);
	}

	class Iterator
	{
	private:
		K* chei;
		V* valori;
		unsigned int index;
	public:
		Iterator(K* chei, V* valori, unsigned int index)
			: chei(chei), valori(valori), index(index){
		}

		struct Reference
		{
			K key;
			V value;
			unsigned int index;
		};

		Reference operator*() const
		{
			return { *chei, *valori, index };
		}

		Iterator& operator++()
		{
			this->chei++;
			this->valori++;
			this->index++;
			return *this;
		}

		bool operator!=(const Iterator& other) const
		{
			return index != other.index;
		}
	};

	Iterator begin()
	{
		return Iterator(chei, valori, 0);
	}

	Iterator end()
	{
		return Iterator(chei+nr, valori+nr, nr);
	}
};

int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20]="result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}
