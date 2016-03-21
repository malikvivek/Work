package way2sms;

import java.net.URLEncoder;
import java.util.ArrayList;
  
public class Credentials {
 private ArrayList< String > list = new ArrayList< String >();
 
 //Set
 public void set(String name, String value) {
  StringBuilder buffer = new StringBuilder();
 
  buffer.append(name);
  buffer.append("=");
  buffer.append(getUTF8String(value));
 
  add(buffer.toString());
 }
 
 //Append
 public void append(String name, String value) {
  StringBuilder buffer = new StringBuilder();
 
  buffer.append("&");
  buffer.append(name);
  buffer.append("=");
  buffer.append(getUTF8String(value));
 
  add(buffer.toString());
 }
 
 //Add
 private void add(String item) {
  list.add(item);
 }
 
 //Get UTF8 String
 private String getUTF8String(String value) {
  String encodedValue = null;
 
  try {
   encodedValue = URLEncoder.encode(value, "UTF-8");
  } catch(Exception exception) {
   System.err.println("Encoding error! Please try agian...");
   System.exit(1);
  }
 
  return encodedValue;
 }
 
 //Is Empty
 public boolean isEmpty() {
  return list.isEmpty();
 }
 
 //Reset
 public void reset() {
  list.clear();
 }
 
 //Get User Credentials
 public String getUserCredentials() {
  StringBuilder buffer = new StringBuilder();
  int size = list.size();
 
  for(int i = 0; i < size; i++)
   buffer.append(list.get(i));
 
  return buffer.toString();
 }
}