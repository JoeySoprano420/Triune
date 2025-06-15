# Triune

| Cognitive Tier | Language Core Equivalent                    |
| -------------- | ------------------------------------------- |
| **Why**        | Logic, conditions, definitions, proof       |
| **How**        | Pattern, matching, polymorphism, analogy    |
| **What**       | Execution steps, instructions, flow control |

| Concept                | Syntax Example                             |
| ---------------------- | ------------------------------------------ |
| Variable Declaration   | `let age := 21`                            |
| Conditional Logic      | `if age > 18 then say "Adult"`             |
| Pattern Matching       | `match weather: when sunny => wear("hat")` |
| Function Definition    | `func greet(who): say "Hello, {who}"`      |
| Logical Truth Types    | `truth x := (a == a)`                      |
| Proof by Contradiction | `if not(x == x): error "Logic failure"`    |

📚 Teaching Model Integration
Triune includes syntax modes for each learner style:

@why_mode → triggers Socratic-style prompts, explanations.

@how_mode → triggers visual metaphors and execution traces.

@what_mode → collapses to pure instruction list for linear learners.

🎮 Interpreter + Mission Mode (VACU Launcher Compatible)
Each coding challenge includes:

🧠 "Why Prompt": A philosophical or logical question.

🔍 "How Puzzle": A pattern or analogy challenge.

📘 "What Task": A direct instruction to implement.

Each style learns the same concept but in their native mode of cognition.

| Stage        | Behavior                                                                  |
| ------------ | ------------------------------------------------------------------------- |
| Lexer        | Parses `why`, `how`, `what` sections individually                         |
| Parser       | Builds 3-part AST (IntentNode, PatternNode, StepNode)                     |
| IR Generator | Separates logical statements from flow instructions                       |
| Evaluator    | Interleaves logical truth evaluation with execution                       |
| Output       | Displays explanation-first, visual-first, or step-first depending on mode |


🧪 Capstone Integration
Users write their own mini-logic evaluator, with symbolic input.


Example user file:

triune

P := true
Q := false
expression := (P and Q) implies (not Q)
evaluate(expression)


Expected Output:

False
Explanation: P is true, Q is false → P and Q = false → implication = true


📊 Future Extensions
🧠 proof blocks — write logical proofs step-by-step

🔍 visualize keyword — generate flowcharts of logic flow

📘 explain keyword — compile into annotated tutorials


🏁 Summary
Triune isn’t just a language.
It’s a learning-embedded cognitive framework in code.

It's how logic feels when you write it.
It’s why truth matters when you debug.
It’s what instruction becomes when structured for the mind.
