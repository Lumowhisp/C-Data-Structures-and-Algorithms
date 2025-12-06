<!-- 🌐 Webpage‑Like Hero Section -->
<div align="center">

<h1 style="font-size:45px; font-weight:900; color:#4FC3F7;">
🧱 Stack in C – Beginner Friendly Guide
</h1>

<p style="font-size:18px; color:#ccc; max-width:600px;">
Welcome to the <b>Stack</b> section of your DSA repository.  
This guide explains stacks using clean visuals, animations, and beginner‑friendly examples.
</p>

<img src="https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/clean.svg" width="100%" />
</div>

---

## 🌟 What is a Stack?

A **Stack** is a linear data structure that follows:

<div align="center">
<h2 style="background:#222; padding:10px; border-radius:10px; display:inline-block;">
🔥 LIFO — Last In, First Out
</h2>
</div>

Meaning the **element inserted last will come out first**.

### 🧩 Real‑Life Examples
- 🍽️ Stack of plates  
- 🔙 Browser history (Back button)  
- ✍️ Undo operation in editors  

---

## 🎬 Visual Animation (Styled & Modern)

Imagine a stack as vertical boxes.  
Below animations simulate **push**, **pop**, and **peek** visually.

---

### 🟦 Start: Empty Stack

```text
┌─────────┐
│  empty  │
└─────────┘
```

---

### 🟦 Step 1: push(10)

```text
    ↑ Top
┌─────────┐
│   10    │
└─────────┘
```

---

### 🟦 Step 2: push(20)

```text
    ↑ Top
┌─────────┐
│   20    │
├─────────┤
│   10    │
└─────────┘
```

---

### 🟦 Step 3: push(30)

```text
    ↑ Top
┌─────────┐
│   30    │
├─────────┤
│   20    │
├─────────┤
│   10    │
└─────────┘
```

---

### 🟥 Step 4: pop() → removes 30

```text
Popped → 30

    ↑ Top
┌─────────┐
│   20    │
├─────────┤
│   10    │
└─────────┘
```

---

### 🟩 Step 5: peek() → shows 20

```text
Top Element → 20

    ↑ Top
┌─────────┐
│   20    │
├─────────┤
│   10    │
└─────────┘
```

---

## 🧠 Core Stack Operations

In C (array-based stack), we usually track:

- `int top;` → index of the **top element**
- `int arr[MAX];` → array to store data

Main operations:

1. **push(x)** → add element at the top
2. **pop()** → remove element from the top
3. **peek() / top()** → see current top element
4. **isEmpty()** → check if stack is empty
5. **isFull()** → check if stack is full (for array implementation)

---

