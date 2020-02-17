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

<p>
  Following is the decleretaion of the structure "data_type" and possible type values:
  </p>

<pre>
struct data_type{
    int type; 
    int value;
};

typedef struct data_type data_type;
</pre>

<pre>
#define PLUS 0
#define MINUS 1
#define MULTIPLY 2
#define DIVIDE 3
#define MOD 4
#define RIGHT 5  // Represents ')'
#define LEFT 6 // Represents '('
#define NUM 7
</pre>
<p>
  For example, when we declare a variable as below:
  </p>
  
<pre>
 data_type myData1, myData2;
 myData1.type = PLUS;
 myData2.type = NUM; myData2.value = 5;
</pre>

<p>
  The variable myData1 represents a plus because its type is PLUS.<strong> Value attributes are only initialized for variables whose types are NUM. </strong>Therefore, the value of the variable myData1 contains trash data. However, both the type and the value attributes of the variable myData2 are intialized because the type of the variable myData2 is NUM.<br>
  
  
  When variables of type "data_type" are put into an array, that is when they start to repserent a fully equation:
</p>
  
<pre>
  data_type a,b,c,d,e,f,g;
  data_type[7] myArr;
  a.type = NUM; a.value = 2;
  b.type = MULTIPLY;
  c.type = LEFT;
  d.type = NUM; d.value = 2;
  e.type = PLUS;
  f.type = NUM; f.value = 3;
  g.type = RIGHT;
  myArr[0] = a;myArr[1] = b;myArr[2] = c;myArr[3] = d;myArr[4] = e;myArr[5] = f;myArr[6] = g;
</pre>
<p>
  So the myArr above repserents the following expression: 
  <pre>2*(2+3)</pre>
  </p>
