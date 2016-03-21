package filetry;
/*
import java.io.*;

public class FileIoTry {
	public static void main(String []args) throws IOException{
		try{
			FileInputStream f1 = new FileInputStream("/var/log/syslog");
			int l;
			l=f1.available();
			int i=1;
			char ch;
			while(i<=l){
				ch=(char)f1.read();
				System.out.print(ch);
				i++;
			}
			f1.close();
		}
		catch(Exception e){
			System.out.println("File Opening Error :"+e);
		}
		//f1.close(); 
	}

}*/

import java.util.Date;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
  
public class FileIoTry {
  public static void main(String[] args) {
 
	   DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
	   //get current date time with Date()
	   Date date = new Date();
	   System.out.println(dateFormat.format(date));
 
	   //get current date time with Calendar()
	   Calendar cal = Calendar.getInstance();
	   System.out.println(dateFormat.format(cal.getTime()));
 
  }
}
