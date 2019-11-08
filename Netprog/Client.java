import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.util.Scanner;
import java.util.Vector;

public class Client {
	private MulticastSocket sender;
	private MulticastSocket receive;
	private int senderPort = 8888;
	private int receivePort = 7777;
	private Scanner scan = new Scanner(System.in);
	private int choose=0;
	private Vector<Data> datas = new Vector<>();

	public Client() {
		try {
			sender = new MulticastSocket(senderPort);
			receive = new MulticastSocket(receivePort);
			
			InetAddress addrSender = InetAddress.getByName("225.0.1.1"); 
			InetAddress addrReceive = InetAddress.getByName("225.0.0.1");
			
			sender.joinGroup(addrSender);
			receive.joinGroup(addrReceive);
			
			Thread t = new Thread(new Runnable() {
				
				@Override
				public void run() {
					while (choose !=3) {
						byte[] buf = new byte[1024];
						DatagramPacket p = new DatagramPacket(buf, buf.length);
						try {
							receive.receive(p);
							ByteArrayInputStream in = new ByteArrayInputStream(p.getData());
							ObjectInputStream ois = new ObjectInputStream(in);
							Data data = (Data) ois.readObject();
							
							System.out.println("Nama Barang  : " + data.getNama());
							System.out.println("Berat Barang : " + data.getBerat());
							System.out.println("Code Barang  : " + data.getCode());
							System.out.println("Harga Barang : " + data.getHarga());
							datas.add(data);
						} catch (Exception e) {
							
						}
						
						
					}
				}
			});
			t.start();
			
			
			while(true){
				System.out.println("1. Add");
				System.out.println("2. View");
				System.out.println("3. Exit");
				choose = scan.nextInt();scan.nextLine();
				
				if(choose ==1){
					System.out.println("Nama : ");
					String nama = scan.nextLine();
					System.out.println("Berat Barang : ");
					int berat = scan.nextInt();scan.nextLine();
					
					Data data = new Data(nama, "", berat, 0);
					
					ByteArrayOutputStream out = new ByteArrayOutputStream();
					ObjectOutputStream oos = new ObjectOutputStream(out);
					oos.writeObject(data);
					
					byte[] buf = out.toByteArray();
					DatagramPacket pkt = new DatagramPacket(buf, buf.length, addrSender, senderPort);
					sender.send(pkt);
				}
				else if(choose == 2){
					for (int i = 0; i < datas.size(); i++) {
						System.out.println("No : "+ (i+1));
						System.out.println("Nama Barang  : " + datas.get(i).getNama());
						System.out.println("Berat Barang : " + datas.get(i).getBerat());
						System.out.println("Code Barang  : " + datas.get(i).getCode());
						System.out.println("Harga Barang : " + datas.get(i).getHarga());
						System.out.println("");
					}
				}
				else if(choose ==3){
					break;
				}
			}
			sender.close();
			receive.close();
			
		} catch (Exception e) {
			
		}
	}

	public static void main(String[] args) {
		new Client();
	}

}
