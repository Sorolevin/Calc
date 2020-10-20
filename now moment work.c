#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>

int secure_1(char val, char data[] );
struct listNode {                                      
   char data[300];
   char key[10]; 
   struct listNode *nextPtr; 
}; 
int hlp_fix(char data[] , char dump_alpha[] );
typedef struct listNode ListNode; 
typedef ListNode *ListNodePtr; 

int insert (ListNodePtr *sPtr,  char *data );
char delet(ListNodePtr *sPtr, char data);
char *my_copy_2(char *out, const char *in );
	struct stack_2 {
 
	long	double alpha;
 
	struct stack *nxtPTR_2;
	};
 
double func_atof(char *p);
typedef struct stack_2  Stack_2;
 
typedef  Stack_2 *node_2;
 int my_isdigit(char alpha);
int my_isalpha(char alpha);
 
node_2 topPTR_2 = NULL;
char *my_strtok( char *s, char *delim); 
char check_stack(node_2 data);
 
int isOperator(char c);
 
int precedence(char data_1, char   data_2);
 
void push_stack(node_2 *topPTR, int value);
 
void push_stack_2(node_2 *topPTR_2,  double value);
 
int isEmpty(ListNodePtr sPtr);
 
double pop_2(node_2 *fix);

char alpha_data[300];
char infix[300];
char postfix[300] ;
double end_line ( char  *data );
 
int in_line( char ( *post ) ,char ( *data ) , ListNodePtr *sPtr );
int main(void) {

ListNodePtr startPtr = NULL; 
double sl = 0;	
int d = 0;
char search_r(ListNodePtr *sPtr,  char *key  );
char data[50]; 
 
   

 for(; alpha_data[0] !=  '0' ;  ){
	 printf("please enter variable,  enter 0 exit \nexample g  =  (4.4 - 65.6 ) / 53\n");
	  fgets( &alpha_data[0], sizeof(alpha_data), stdin);
	
			data[d++] = alpha_data[0];
			insert( &startPtr, alpha_data) ;
		}		
	data[d -  1] = '\0';
	puts(" ");

	 printf("please enter  data:\nexample  b  *  (4+4 - 65.  -  g ) / a\n");

 fgets(&infix[0], sizeof(infix), stdin);
 
 hlp_fix(infix , data  );
 
if (in_line( postfix,infix , &startPtr ) == 1){
 	
 
 	puts(" ");	
	sl =   end_line(  postfix);
	printf("%.2f\n", sl );
 }else{
 	puts("error");
 }
 
return 0;
}


int secure_1(char val , char data[]     ){
	return 	(!isalpha(val)  ||  !strchr(data , val)    )                && !isOperator(val)  && !isdigit(val)  && val != '('  && val != ')' &&  val != '.'  ;
}
 
int hlp_fix(char data[]  , char dump_alpha[] ){
int run = 0;
char prev = '0';
int count_bracket = 0 ;
puts(dump_alpha);
	if(my_isdigit(data[0]) || my_isalpha(data[0])    ){
					 prev = data[0];
					}
	else if (data[0] == '('){
			count_bracket++;
			 prev = data[0];
	}
 			else{
				  
					puts("!!!  first error  !!!");
				  	exit(1);
				  }

for(run = 1;data[run] != '\0' ;run++){
	
	
	if ( data[run + 1]    == '\0'  &&  isOperator(prev )           ){
					
					puts("!!! error  isOperator  !!!");
				  	exit(1);
			}
	/*
	вставить 
	обработку букв для выражений
	
	
	*/
	
	if(isgraph(data[run] )){
		
		if( secure_1(data[run], dump_alpha )  ) { 
		  printf("!!! error  this no list = %c !!!",  data[run] );
			exit(1);
		}
		
		if(prev == '.' ){
			
			if( data[run  - 1 ]   == '.' && my_isdigit(data[run])      )   {
						 prev = data[run];
				}
		
		 else{
				  	
					puts(" !!! error point !!!");
				  	exit(1);
				  }
			}
		
			else	if(my_isdigit(prev)  ){
				
			
			if(  data[run] == ')' )   {
					 	 prev = data[run];
					 	--count_bracket;
					 }
				
			else	if(	 (	my_isdigit(data[ run - 1  ])       	||	data[run - 1 ] == '.' || 
					
					isOperator(data[run]) )    ){
					 prev = data[run];
					
			}
					 
			else{
				  puts("error  isdigit");
				  	exit(1);
				  }
				}
		
			else	if(isOperator(prev)){
			
				if( (my_isdigit(data[run])  || my_isalpha(data[run] )       )   ){
						 prev = data[run];
				}
					else if ( data[run] == '('  ){
							 prev = data[run];
							 count_bracket++;
					}
					
			else{
				  	
					puts("error  isOperator");
				  	exit(1);
				  }
				}
			
			else	if(prev == '(' ){
			
				if( (my_isdigit(data[run] )  || my_isalpha(data[run] )  ) ){
					 prev = data[run];
				
				}
				else if ( data[run] == '('){
					 count_bracket++;
					 prev = data[run];
				}
				
				
				else{
				  	puts("error  (");
				  	exit(1);
				  }
				
			}
			
		
		
		else if (my_isalpha(prev) ){
				
				
			if(my_isalpha(data[run]) ){
			puts("error  alpha");
				  	exit(1);
			}	
				
				
				if(data[run] == ')' ){
					count_bracket--;
				}
				
				 prev = data[run];
					
			
			
		}
		
		
		else	if(prev == ')' ){
				
				if(		isOperator(data[run])    ){
				
					 prev = data[run];
				}
				else if(data[run] == ')'   ){
					 count_bracket--;
					 prev = data[run];
				}
				
				else{
				  	printf("\n" );
					puts("error  )");
				  	exit(1);
				  }	
			}
	/*
	else {
		puts("error else fuch ");
		exit(1);
		}
	*/
	}
} 

if(	count_bracket != 0 ){
	printf("brack  error  %d\n", count_bracket  );
	exit(1);
}

return 0;
}

 
double end_line( char ( *data ) ){
 
double x = 0 , y = 0, sum = 0,ml = 0    ; 
char	*point =   strtok(  (data), " " );
 
 
	while( point   ){
 
		if( my_isdigit(  *point ) ){
 
			ml  = func_atof( (char *)  point  )  ;
			push_stack_2( &topPTR_2,ml);
 
			}	
 
		else if ( isOperator ( *point ) == 1 ){
 
			y =	pop_2(&topPTR_2);
			x = pop_2(&topPTR_2);	 	
 
		if( *point  == '^' ){
 
			sum  =  pow(x, y) 	  ;
			push_stack_2(  &topPTR_2, sum  );
			}
 
 
			if( *point  == '*' ){
 
 
				 push_stack_2(&topPTR_2,    	x * y         );
			 }
 
		 	if( *point == '+' ){
 
				 push_stack_2(&topPTR_2, 	x + y  	 );
			}
 
	     	if(  *point == '/' ){
 
				push_stack_2(&topPTR_2, x / y    );
			 }
 
			 if(   *point == '-' ){
 
						 push_stack_2(&topPTR_2,   x - y     );
				}
			}
 
						point = strtok(NULL , " " ) ;
			
		}
 
 
	return    pop_2(&topPTR_2);
}
 
 char *change(ListNodePtr *sPtr   ,char cnt,  char  ( *base ) , int ia ){

	ListNodePtr currentPtr = *sPtr;	
	
	if (  ia == 0     ) {
	
		while (currentPtr->nextPtr != NULL) {
			
				if( cnt     == currentPtr->nextPtr->key[0] ){
			
					return  &currentPtr->nextPtr->data[0] ;
			
				}
		currentPtr = currentPtr->nextPtr; 
		}  
	}

else	if(    ia == 1)  {
 			return   &(*base ); 
	  }
}  
 
 int in_line( char ( *post ) ,char ( *data ) ,ListNodePtr *sPtr ){
	 
char * change(ListNodePtr *sPtr    ,char cnt ,char *base , int ia );
int  swp_count = 1;
char *chg; 
int ia = 0;

 
 
int j = 0  , k = 0 , d = 0 ;
 
  chg = &(*data ); 
 
	data[299]  = ')';
    push_stack_2(&topPTR_2, '(');

 
	for ( k = 0 ;  	check_stack((void *) &topPTR_2) != 1  ; ++k)  {
 		
		if( my_isalpha (  *(chg +  k )    )  ){
			swp_count = k;
			ia = 1;
					
			chg 	= change( sPtr    , *(chg +  k )  , data , 0 );	
			k = 0;
			
		}
		
		if(*(chg + (k - 1)  ) == ')' && *(chg + (k  ) ) == '\0'    && ia == 1 ){
			k = swp_count;
			ia = 0;
	
			chg 	= change( sPtr    , k , data , 1 );	
		
		}
 				
		if (   my_isdigit( 	*(chg + k  )    )   ||  	*(chg  + k  )  == '.'  ) {
 
				*(post  + j++ )   = 	*(chg  + k  ) ;

		}
 
		if (	*(chg  + k  )  == '(') {
 
			push_stack_2(&topPTR_2,  *(chg  + k  )  )  ;
 
		}
			if (isOperator( *(chg  + k  )  ) == 1 || *(chg  + k  ) == ')'  ) {
				*(post  + j++ )  = ' ';
			for (;         precedence(topPTR_2->alpha,  *(chg  + k  )   ) != -1 ; ) {
 
			*(post  + j++ )= pop_2( &topPTR_2);
			*(post  + j++ )  = ' ';	
		}
 
			push_stack_2(&topPTR_2, 	*(chg  + k  )  );
			push_stack_2(&topPTR_2, ' ' );
 
		}
 
		if (	(*(chg  + k  ) ) == ')') {
 
		d =  pop_2( &topPTR_2);
			for (; d != '('     ; 	d = pop_2(&topPTR_2)) {
					*(post  + j++ )  = d;
 
				}
			}
 		}
 
	return 1;
	}

void push_stack_2(node_2 *topPTR_2,  double value) {
 
	node_2 newPTR = malloc(sizeof(Stack_2));
 
	if (newPTR != NULL) {
 
		newPTR->alpha = value;
		newPTR->nxtPTR_2 = (void *)  *topPTR_2;
		*topPTR_2 = newPTR;
 
	}
	else {
 
		puts("error");
	}
}

double pop_2(node_2 *fix) {
 
	double  value = 0;
	node_2 temp = *fix;
	value = (*fix)->alpha;
	*fix = (void *)   (*fix)->nxtPTR_2;
	free(temp);
 
return value;
}
 
char check_stack(node_2 data) {
 
	return data->alpha   ==  0  ;
 
}
 
int isOperator(char c) {
 
	return c == '/' || c == '*' || c == '-' || c == '+' || c == '^' ;
 

}

 
int precedence(char data_1, char  data_2) {
 
	switch(data_1){
		case '(':	
 
		return -1;
		case '^':
 
			if(data_2 == '^' ){
				return    0;
				} 
 
	 	case 	'/' : 
        case 	'*':        
 
			if(data_2 == '^' ){
					return    -1;
				} 
 
			else if( data_2 == '/' || data_2 == '*'     ){
					return    0;
					}	
 
			else if( data_2 == '+' || data_2 == '-'     ){
						return     1;
					}
	
		case  '+':
		case  '-':		
 
		if(data_2 == '^'  || data_2 == '/' || data_2 == '*'        ){
			return    -1;
				} 
		else{
			return     0;
		}
	}
return 0;
}


int insert(ListNodePtr *sPtr,  char *data  ){ 
   char *buf;
   char key = '0';
   int lng = 0;
	int cnt = 0;
  
  	buf = strtok( data,"=");
   
   ListNodePtr newPtr = malloc(sizeof(ListNode));
	
   if (newPtr != NULL) { 
   
    for(cnt = 0 ;  buf != (char *)'\0'  ; buf = strtok(NULL,"=") ) {
				
	
	
	
	
	  if( my_isalpha( *buf)   ){
	  		
			  my_copy_2( newPtr->key ,  buf ) ; 
		  
		  }

		else {
				newPtr->data[0] = '(';
				my_copy_2( &newPtr->data[1] , buf ) ;
				lng  =	strlen(newPtr->data);	
				newPtr->data[lng ] = ')';
				newPtr->data[lng + 1 ] = '\0';
				hlp_fix( 	newPtr->data , 0 );
		
		}
			cnt++;
	  }
	  if( (cnt % 2  ) !=  0   && data[0] != '0'   ){
	  	  printf("%d\n", cnt );
		puts("err strtok");
	  	exit(1);
	  }
	  
	  newPtr->nextPtr = NULL; 
	  ListNodePtr previousPtr = NULL;
      ListNodePtr currentPtr = *sPtr;

   
      while (currentPtr != NULL &&  strcmp( &key  ,currentPtr->key) == 1 ) {
         previousPtr = currentPtr;   
         currentPtr = currentPtr->nextPtr; 
      }                                          

     
      if (previousPtr == NULL) { 
         newPtr->nextPtr = *sPtr;
         *sPtr = newPtr;
      } 
      else { 
         previousPtr->nextPtr = newPtr; 
         newPtr->nextPtr = currentPtr;
      } 
   } 
   else {
      printf("%c not inserted. No memory available.\n", key);
   } 
return 1;
} 

int isEmpty(ListNodePtr sPtr)
{ 
   return sPtr == NULL;
} 


double func_atof(char *p){
	double	 integer = 0.0, div = 1.0 , fract = 0.0 , sign = 1.0;
   if(   *p == 45  ){sign = -1.0, *p++ ; }
	while (  my_isdigit(*p)  ) { 
		integer = ( *p++ )  +  (10.0   *   integer)  -  48.0 ; 
		}
	if(*p == 46  ){
	(*p++ ) ;
	while (   my_isdigit(*p) )  {
		fract = ( *p++ )  +  (10.0   *   fract)  -  48.0  ; 
		div *= 10;		
		}
    }
  return    (integer  +   fract  / div )  * sign    ;
}

int my_strcmp(const char *out, const char *in   ){
  for( ;*(in) , *(out) &&  *(in) == *(out); *out++,*in++  );
	   return   *in <= *out ?  *out > *in   : -1   ;
	}


char *my_copy_2(char *out, const char *in ){
	int	m = 0;
		while(   (   *(out + m ) = *(in + m )      )    ){
		m++;
		}  
return out;


  }

int my_isdigit(char alpha){
	return  (alpha >=  48)   && ( alpha <= 57     ); 
}

int my_isalpha(char alpha){
	return     (  (alpha >=  65   &&  alpha <=  90)   ||  (alpha >=  97   &&  alpha  <=    122)   )  ; 
}
