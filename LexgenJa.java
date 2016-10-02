import java.util.Iterator;





public class Fancy implements Iterator<String> {
	
	String str = "abcd";
	int lex;
	
	int[]  arr=new int[100] ;
	
	public Fancy(int x){
		lex=x;
	}
	
	
	
	
	public static void main(String[] args) {
		
		Fancy f = new Fancy(5);
		while(f.hasNext())
		System.out.println(f.next());
	}

	

	public boolean hasNext() {
		if(arr[lex]==1){
			return false;
		}
		return true;
	}

	public String next() {
		// TODO Auto-generated method stub
		int n=0;
		
		String st = "";
		for(int i=lex-1;i>=0;i--){
			st+=str.charAt(arr[i]);
		}
		for(int i=0;i<=lex;i++){
			
			if(arr[n]==3){
				arr[n]=0;
				n++;
				
			}
			else{
				break;
			}
		}
		arr[n]++;
		
		
		
		
		return st;
	}

	public void remove() {
		// TODO Auto-generated method stub
		
	}

}
