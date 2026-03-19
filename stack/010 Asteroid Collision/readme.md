🚀 Asteroid Collision – Complete Guide (Stack)
📌 Problem Summary

You are given an array asteroids where:

Positive → moving right ➡️

Negative → moving left ⬅️

💥 Collision Rules:

Only happens when:

right-moving asteroid meets left-moving asteroid

Smaller one explodes

If equal → both explode

Survivors continue moving

🧾 Example
Example 1:
Input: [5, 10, -5]
Output: [5, 10]

👉 Explanation:

10 and -5 collide → 10 survives

Example 2:
Input: [8, -8]
Output: []

👉 Explanation:

Equal magnitude → both destroyed 💥

Example 3:
Input: [10, 2, -5]
Output: [10]

👉 Explanation:

2 vs -5 → 2 destroyed

10 vs -5 → 10 survives

🧠 Intuition (MOST IMPORTANT 🔥)
🔑 Who will collide?

👉 Only when:

previous > 0  AND  current < 0

Why?

Right ➡️ meets left ⬅️ → collision

Same direction → never meet

💡 How Stack Came Into Mind?

Think like this:

“I need to compare current asteroid with previous ones… but only the latest active one matters”

That’s exactly what a stack does 👇

Stores alive asteroids

Gives quick access to last one (top)

🧠 Mental Model

Stack = “survivors so far”

For each asteroid:

Check collision with stack top

Resolve until stable

Push if survives

⚙️ Approach
Step-by-step:

Traverse array

For each asteroid:

While collision possible:

Compare sizes

Pop smaller one

Decide if current survives

Push if not destroyed

Return stack


 
