## Overall
- Passing 86/86 (100.0%) seen tests
- Passing 84/115 (73.04%) unseen tests
- Passing 170/201 (84.58%) total tests

Good job!

## General / DevOps feedback
- Good effort at using git branches. However from the branch history seems a bit chaotic
- Frequent commits with good messages
  - Good attempt with using pull requests!
- Your files are neatly organised, I like the file structure, it's easy to navigate
- You added your own testcases which is very good
- Also nice work splitting up your files, they are all reasonably sized. Nice work splitting up declarations and definitions into cpp and hpp files

## Code feedback
- In your parser there are quite a few unused tokens
- Most things in your parser are type node - it is probably better to specify the exact type where possible
  - In your AST classes every child member is of type Node. It would be better to specify the types here too
- Having to EmitRISC methods (with and without a destreg parameter) is not the nicest implementation. Either store the destreg in the context, or always pass it as a separate parameter. How does the caller know which one to call?
- You could have had a cleaner AST by really thinking about what is necessary to generate the code. Is storing semicolons in your AST really needed? By storing all these nodes in your AST you are doing more work in the codegen than you should
- node->getEntity() function is code smell. The parent class should not have to know what type the child is, it should just be able to call the EmitRISC method on it
- The interface of the Node class should be simpler. All you need is a single EmitRISC method. getId and getValue (and two! getType) methods don't make sense for most nodes.
- It should be very rare that you would need to use protected members/methods and I don't think it is necessary in the case of this compiler
- The Context class's members should be private. You don't want these  members to be modified by anyone else / to be accidentally modified
- Overall good object oriented concepts applied
