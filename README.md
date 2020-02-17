# Shunting Yard Algorithm Implementation in C
<p>
  This projects includes a shunting yard algorithm coded in C. To be used as auxiliary data structures, queue and stack implementations are added.
</p>

<p>
  <strong>Input and Output Types: </strong>Both are strings <strong>but</strong> at the end of the main function, the variable <strong>input</strong> behaves as an array of pointer of the structure type "data_type".
</p>

<p>
  <strong>Precedende and Associativity:</strong> The same as classic C operators.
</p>

<p>
  <strong>Other Important Notes: </strong> STDIN and STDOUT are used as io stream. Input stream executes when hits the <strong>new line character</strong> but that can be easily changed by following the documentations in the code.
</p>

  <p><strong>Example call:</strong><br>
  Input:<br>
  <code>12+(52*2)%7-5</code><br>
  Output:<br>
  <code>12522*7%+5-</code></p>

<h3>The Structure "data_type" and How to Interpret It</h3>
<pre>
struct data_type{
    int type; 
    int value;
};

typedef struct data_type data_type;
</pre>
