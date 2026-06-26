# 🔓 `public` vs 🔒 `private` — CPP00 Guide

> **The difference, finally clear** — explained with your own `Contact` class from the PhoneBook.
>
> _Note: this is the static Markdown version. For the interactive demo + dark-theme design, open [`public-vs-private.html`](public-vs-private.html) in a browser._

---

## 01 · The answer in 10 seconds

| | 🔓 `public` | 🔒 `private` |
|---|---|---|
| **Who can access it** | Accessible from **anywhere** | **Inside the class only** |
| **Meaning** | The **front door** of your class | The **hidden inside** of your class |
| **From your `main`** | ✅ Allowed | ❌ Forbidden (compile error) |

> 💡 **The real question isn't _"who"_ is allowed, but _"WHERE is the code written?"_**
> The same attribute is accessible **from inside** the class and **forbidden from outside**.

---

## 02 · The house analogy 🏠

Picture a **class = a house**. There's what happens **inside**, and what's visible **from the street**.

| 🔒 `private` · the inside | 🔓 `public` · the façade |
|---|---|
| 🛋️ Your living room, your bedroom, your diary — nobody in the street touches them directly | 🔔 The doorbell, the mailbox, the door — **everyone** in the street can use them |
| 👨‍👩‍👧 Only the **residents** (the class's methods) can reach and modify them | 🚪 These are your **public methods**: `setFirstName()`, `getFirstName()`… |
| 🤫 This is exactly your `_darkestSecret`: a secret, so it's **hidden** | 🤝 The only "clean" way for the outside to interact with the inside |

---

## 03 · Who can access what?

| Where you write the code… | access to `public` | access to `private` |
|---|:---:|:---:|
| **From inside the class** (e.g. in `Contact.cpp`) | ✅ YES | ✅ YES |
| **From the outside** (e.g. in your `main()`) | ✅ YES | ❌ NO |
| **From a child class** (inheritance, CPP02/03) | ✅ YES | ❌ NO* |

> \* For child classes there's a 3rd keyword, `protected` — see section 08.

---

## 04 · Your `Contact` class, dissected

Here's your real `Contact.hpp`. Look at the two blocks: the **private data** on top, the **public interface** below.

```cpp
class Contact
{
private:                          // 🔒 THE DATA — hidden from the world
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;   // a "secret"... so it's private, makes sense!

public:                           // 🔓 THE INTERFACE — the front door
    void        setFirstName(std::string str);  // to WRITE
    std::string getFirstName(void);             // to READ
    // ... same for lastName, nickname, etc.
};
```

And in `Contact.cpp`, the setter **touches** the private attribute… and that's **allowed**, because we're **inside the class**:

```cpp
void Contact::setFirstName(std::string str)
{
    this->_firstName = str;   // ✅ OK : we're INSIDE the Contact class
}
```

---

## 05 · Same line, different result

The exact same idea **compiles or blows up** depending on where you write it. Here's the interactive demo, as a static table:

| Action | 🏠 Inside (`Contact.cpp`) | 🌍 Outside (`main.cpp`) |
|---|---|---|
| Read/write the **private** `_firstName` directly | ✅ `this->_firstName = "Bob";` | ❌ `contact._firstName = "Bob";` |
| Call the **public** `setFirstName()` | ✅ `this->setFirstName("Bob");` | ✅ `contact.setFirstName("Bob");` |
| Read the **private** `_darkestSecret` directly | ✅ `this->_darkestSecret` | ❌ `contact._darkestSecret` |
| Read the secret via the **public** getter | ✅ `this->getDarkestSecret();` | ✅ `contact.getDarkestSecret();` |

> 📍 **Inside** a method of `Contact` → you have access to **EVERYTHING** (public + private).
> 📍 In `main()` → you only have access to **public**.

---

## 06 · What happens if you cheat

If from your `main` you try to reach a private attribute directly, the code **doesn't even compile**. It's not a runtime crash — it's the **compiler** stopping you right away.

```cpp
Contact contact;

contact.setFirstName("Bob");        // ✅ OK    → setFirstName is public
std::cout << contact.getFirstName(); // ✅ OK    → getFirstName is public

contact._firstName = "Bob";          // ❌ ERROR → _firstName is private
std::cout << contact._darkestSecret; // ❌ ERROR → _darkestSecret is private
```

The compiler refuses, like this:

```
error: 'std::string Contact::_firstName' is private within this context
    contact._firstName = "Bob";
            ^~~~~~~~~~
note: declared private here
    std::string _firstName;
                ^~~~~~~~~~
```

> 👉 **The fix:** go through the public front door → `contact.setFirstName("Bob");`

---

## 07 · Why bother? Encapsulation

> "Why hide my variables when I could just make everything public?" Here are the real reasons — this is **the heart of OOP**.

1. **🛡️ Protect the data** — a setter can **validate** before writing (e.g. reject an empty phone number). With direct public access, anyone can put anything.
2. **🔧 Freedom to change the inside** — as long as your public methods keep the same names, you can **rewrite everything inside** without breaking the code that uses your class.
3. **🎯 A clear interface** — whoever uses `Contact` only sees `set`/`get`. They don't need to know how it's stored inside.
4. **🚫 Avoid invalid states** — you control exactly how your object can be modified. Fewer surprises, fewer "impossible" bugs.

---

## 08 · The bonus nobody tells you

- **`struct` vs `class`** — In C++, the **only** difference is the default access: `class` → everything is `private` by default, `struct` → everything is `public` by default. That's it!
- **The underscore `_`** — The `_` in front of `_firstName` isn't required in C++. It's a **convention** (42 and many others) to spot a private attribute at a glance.
- **Checked at compile time** — `private` is a **compiler** barrier, not a runtime security. Break the rule and it won't compile — it won't "crash" later.
- **It's per-class, not per-object** — A method of `Contact` can read the private attributes of **another** `Contact` (handy for the copy constructor). The barrier protects from *outside the class*, not between objects of the same class.
- **What about `protected`? (coming up)** — It's like `private`, but **child classes** (inheritance) can access it too. You'll meet it in **CPP02/03**.

---

## 📌 Key takeaways

- ✅ **`public`** = accessible from anywhere (your `main`, other classes).
- ✅ **`private`** = accessible **only from inside** the class.
- ✅ The golden rule: **"where is the code written?"** — not "who".
- ✅ Put **data in private** and expose **methods in public** (the getters/setters) = **encapsulation**.
- ✅ Breaking `private` from the outside = **compile error**, never a silent crash.
- ✅ Your PhoneBook does exactly this: `Contact` hides its fields, everything else goes through `set`/`get`.

---

_CPP00 · public vs private — re-read your `Contact.hpp`, it's all there 🙂_
