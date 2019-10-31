import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.util.Random;

public class Server {
	private MulticastSocket sender;
	private MulticastSocket receive;
	private int senderPort = 7777;
	private int receivePort = 8888;
	private Random rand = new Random();
	
	public Server() {
		try {
			sender = new MulticastSocket(senderPort);
			receive = new MulticastSocket(receivePort);
			
			InetAddress addrSender = InetAddress.getByName("225.0.0.1"); 
			InetAddress addrReceive = InetAddress.getByName("225.0.1.1");
			
			sender.joinGroup(addrSender);
			receive.joinGroup(addrReceive);
			
			while (true) {
				byte[] buf = new byte[1024];
				DatagramPacket p = new DatagramPacket(buf, buf.length);
				receive.receive(p);
				
				ByteArrayInputStream in = new ByteArrayInputStream(p.getData());
				ObjectInputStream ois = new ObjectInputStream(in);
				Data data = (Data) ois.readObject();
				
				String code = generate();
				data.setCode(code);
				int harga = 1000*data.getBerat();
				data.setHarga(harga);
				
				System.out.println("Nama Barang  : " + data.getNama());
				System.out.println("Berat Barang : " + data.getBerat());
				System.out.println("Code Barang  : " + data.getCode());
				System.out.println("Harga Barang : " + data.getHarga());
			
				ByteArrayOutputStream out = new ByteArrayOutputStream();
				ObjectOutputStream oos = new ObjectOutputStream(out);
				oos.writeObject(data);
				
				buf = out.toByteArray();
				DatagramPacket pkt = new DatagramPacket(buf, buf.length, addrSender, senderPort);
				sender.send(pkt);
			}
			//sender.close();
			//receive.close();
			
		} catch (Exception e) {
			
		}
	}
	
	public Integer random(int max , int min){
		int r = rand.nextInt(max-min)+min;
		return r;
	}
	
	public String generate(){
		String result = "";
		result+= "AA-";
		result+= random(3, 0).toString();
		result+= random(7, 4).toString();
		result+= random(9, 8).toString();
		return result;
	}
	
	public static void main(String[] args) {
		new Server();
	}
	
}
