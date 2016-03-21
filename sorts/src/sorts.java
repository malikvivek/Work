import java.util.*;
public class sorts {
	void exchange_sort(int b[], int high){
		int i,j;
		for(i=0;i<high-1;i++){
			for(j=i+1;j<high;j++){
				if(b[i]>b[j]){
					int temp;
					temp=b[i];
					b[i]=b[j];
					b[j]=temp;
				}
			}
		}
		for(i=0;i<high;i++){
			System.out.print(b[i]);
		}	
	}

	void bubble_sort(int b[], int high){
		int i,j;
		for(i=0;i<high;i++){
			for(j=high-1;j>=i+1;j--){
				if(b[j]<b[j-1]){
					int temp;
					temp=b[j];
					b[j]=b[j-1];
					b[j-1]=temp;
				}
			}
		}
		for(i=0;i<high;i++){
			System.out.print(b[i]);
		}
	}
	void run_prg(){
		System.out.println("Sorts");
		int arr[] = new int[50];
		int n,i;
		Scanner inp = new Scanner(System.in);
		System.out.println("Enter no. of elements in the array:");
		n=inp.nextInt();
		System.out.println("Enter elements of the array\n");
		for(i=0;i<n;i++){
			arr[i]=inp.nextInt();
		}
		System.out.println("The Sorted Array is:");
		bubble_sort(arr,n);
		exchange_sort(arr,n);
	}
	public static void main(String []args){
		sorts obj=new sorts();
		obj.run_prg();
	}
}
