import java.io.Serializable;

public class Data implements Serializable{
	private String nama,code;
	private int berat,harga;
	
	public Data() {
		// TODO Auto-generated constructor stub
	}

	public Data(String nama, String code, int berat, int harga) {
		super();
		this.nama = nama;
		this.code = code;
		this.berat = berat;
		this.harga = harga;
	}

	public String getNama() {
		return nama;
	}

	public void setNama(String nama) {
		this.nama = nama;
	}

	public String getCode() {
		return code;
	}

	public void setCode(String code) {
		this.code = code;
	}

	public int getBerat() {
		return berat;
	}

	public void setBerat(int berat) {
		this.berat = berat;
	}

	public int getHarga() {
		return harga;
	}

	public void setHarga(int harga) {
		this.harga = harga;
	}
	
	

}
