# 🔓 `public` vs 🔒 `private` — Guide CPP00

> **La différence enfin claire** — expliquée avec ta propre classe `Contact` du PhoneBook.
>
> _Note : ceci est la version Markdown statique. Pour la démo interactive + le design sombre, ouvre [`public-vs-prive.html`](public-vs-prive.html) dans un navigateur._

---

## 01 · La réponse en 10 secondes

| | 🔓 `public` | 🔒 `private` |
|---|---|---|
| **Qui peut y accéder** | Accessible de **partout** | **Intérieur de la classe uniquement** |
| **Signification** | La **porte d'entrée** de ta classe | L'**intérieur caché** de ta classe |
| **Depuis ton `main`** | ✅ Autorisé | ❌ Interdit (erreur de compilation) |

> 💡 **La vraie question n'est pas _« qui »_ a le droit, mais _« OÙ est écrit le code ? »_**
> Le même attribut est accessible **depuis l'intérieur** de la classe et **interdit depuis l'extérieur**.

---

## 02 · L'analogie de la maison 🏠

Imagine une **classe = une maison**. Il y a ce qui se passe **à l'intérieur**, et ce qui est visible **depuis la rue**.

| 🔒 `private` · l'intérieur | 🔓 `public` · la façade |
|---|---|
| 🛋️ Ton salon, ta chambre, ton journal intime — personne dans la rue n'y touche directement | 🔔 La sonnette, la boîte aux lettres, la porte — **tout le monde** dans la rue peut les utiliser |
| 👨‍👩‍👧 Seuls les **habitants** (les méthodes de la classe) peuvent y accéder et les modifier | 🚪 Ce sont tes **méthodes publiques** : `setFirstName()`, `getFirstName()`… |
| 🤫 C'est exactement ton `_darkestSecret` : un secret, donc **caché** | 🤝 Le seul moyen « propre » pour l'extérieur d'interagir avec l'intérieur |

---

## 03 · Qui peut accéder à quoi ?

| D'où tu écris le code… | accès à `public` | accès à `private` |
|---|:---:|:---:|
| **Depuis l'intérieur de la classe** (ex : dans `Contact.cpp`) | ✅ OUI | ✅ OUI |
| **Depuis l'extérieur** (ex : dans ton `main()`) | ✅ OUI | ❌ NON |
| **Depuis une classe enfant** (héritage, CPP02/03) | ✅ OUI | ❌ NON* |

> \* Pour les classes enfants, il existe un 3ᵉ mot-clé, `protected` — voir section 08.

---

## 04 · Ta classe `Contact`, décortiquée

Voici ton vrai `Contact.hpp`. Regarde les deux blocs : les **données privées** en haut, l'**interface publique** en bas.

```cpp
class Contact
{
private:                          // 🔒 LES DONNÉES — cachées du monde
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;   // un "secret"... donc privé, logique !

public:                           // 🔓 L'INTERFACE — la porte d'entrée
    void        setFirstName(std::string str);  // pour ÉCRIRE
    std::string getFirstName(void);             // pour LIRE
    // ... idem pour lastName, nickname, etc.
};
```

Et dans `Contact.cpp`, le setter **touche** à l'attribut privé… et c'est **autorisé**, parce qu'on est **à l'intérieur de la classe** :

```cpp
void Contact::setFirstName(std::string str)
{
    this->_firstName = str;   // ✅ OK : on est DANS la classe Contact
}
```

---

## 05 · Même ligne, résultat différent

La même idée **compile ou plante** selon l'endroit où tu l'écris. Voici la démo interactive, en tableau statique :

| Action | 🏠 Intérieur (`Contact.cpp`) | 🌍 Extérieur (`main.cpp`) |
|---|---|---|
| Lire/écrire l'attribut **privé** `_firstName` directement | ✅ `this->_firstName = "Bob";` | ❌ `contact._firstName = "Bob";` |
| Appeler la méthode **publique** `setFirstName()` | ✅ `this->setFirstName("Bob");` | ✅ `contact.setFirstName("Bob");` |
| Lire le **privé** `_darkestSecret` directement | ✅ `this->_darkestSecret` | ❌ `contact._darkestSecret` |
| Lire le secret via le getter **public** | ✅ `this->getDarkestSecret();` | ✅ `contact.getDarkestSecret();` |

> 📍 **À l'intérieur** d'une méthode de `Contact` → tu as accès à **TOUT** (public + private).
> 📍 Dans `main()` → tu n'as accès qu'au **public**.

---

## 06 · Ce qui se passe si tu triches

Si depuis ton `main` tu essaies d'accéder directement à un attribut privé, le code **ne compile même pas**. Ce n'est pas un crash à l'exécution — c'est le **compilateur** qui te bloque tout de suite.

```cpp
Contact contact;

contact.setFirstName("Bob");        // ✅ OK    → setFirstName est public
std::cout << contact.getFirstName(); // ✅ OK    → getFirstName est public

contact._firstName = "Bob";          // ❌ ERREUR → _firstName est private
std::cout << contact._darkestSecret; // ❌ ERREUR → _darkestSecret est private
```

Le compilateur refuse, comme ça :

```
error: 'std::string Contact::_firstName' is private within this context
    contact._firstName = "Bob";
            ^~~~~~~~~~
note: declared private here
    std::string _firstName;
                ^~~~~~~~~~
```

> 👉 **La solution :** passer par la porte d'entrée publique → `contact.setFirstName("Bob");`

---

## 07 · Pourquoi s'embêter ? L'encapsulation

> « Pourquoi cacher mes variables alors que je pourrais tout mettre en public ? » Voici les vraies raisons — c'est **le cœur de la POO**.

1. **🛡️ Protéger les données** — un setter peut **vérifier** avant d'écrire (ex : refuser un numéro vide). En public direct, n'importe qui peut mettre n'importe quoi.
2. **🔧 Liberté de changer l'intérieur** — tant que tes méthodes publiques gardent le même nom, tu peux **tout refaire à l'intérieur** sans casser le code qui utilise ta classe.
3. **🎯 Une interface claire** — celui qui utilise `Contact` voit seulement `set`/`get`. Il n'a pas à savoir comment c'est rangé dedans.
4. **🚫 Éviter les états invalides** — tu contrôles exactement comment ton objet peut être modifié. Moins de surprises, moins de bugs « impossibles ».

---

## 08 · Le bonus que personne ne te dit

- **`struct` vs `class`** — En C++, la **seule** différence est l'accès par défaut : `class` → tout est `private` par défaut, `struct` → tout est `public` par défaut. C'est tout !
- **L'underscore `_`** — Le `_` devant `_firstName` n'est pas obligatoire en C++. C'est une **convention** (42 et beaucoup d'autres) pour repérer d'un coup d'œil un attribut privé.
- **Vérifié à la compilation** — `private` est une barrière **du compilateur**, pas une sécurité à l'exécution. Si tu violes la règle, ça ne compile pas — ça ne « plante » pas plus tard.
- **C'est par classe, pas par objet** — Une méthode de `Contact` peut lire les attributs privés d'un **autre** `Contact` (utile pour le constructeur de copie). La barrière protège de *l'extérieur de la classe*, pas entre objets d'une même classe.
- **Et `protected` ? (à venir)** — C'est comme `private`, mais les **classes enfants** (héritage) y ont accès aussi. Tu le rencontreras en **CPP02/03**.

---

## 📌 À retenir

- ✅ **`public`** = accessible de partout (ton `main`, autres classes).
- ✅ **`private`** = accessible **uniquement depuis l'intérieur** de la classe.
- ✅ La règle d'or : **« d'où est écrit le code ? »** — pas « qui ».
- ✅ On met les **données en private** et on expose des **méthodes en public** (les getters/setters) = **encapsulation**.
- ✅ Violer `private` depuis l'extérieur = **erreur de compilation**, jamais un crash silencieux.
- ✅ Ton PhoneBook fait exactement ça : `Contact` cache ses champs, le reste passe par `set`/`get`.

---

_CPP00 · public vs private — relis ton `Contact.hpp`, tout est là 🙂_
