import java.io.*;
import java.util.*;

public class Zoo {
    private ArrayList<Enclosure<? extends Animal>> enclosures;
    private float ticketPrice;

    public Zoo() {
        this.enclosures = new ArrayList<Enclosure<? extends Animal>>();
        this.ticketPrice = 0;
        // Inisialisasi this.enclosures dan this.ticketPrice
    }

    public void addEnclosure(Enclosure<? extends Animal> enc) {
        if (!enc.isEmpty()) {
            this.enclosures.add(enc);
        }
        // Menambahkan Enclosure enc ke dalam this.enclosures apabila enc tidak kosong
    }

    public void updateTicketPrice() {
        float newTicketPrice = 0;
        for (int i = 0; i < this.getEnclosureCount(); i++) {
            Enclosure enc = this.enclosures.get(i);
            if (enc.safeForPetting()) {
                newTicketPrice += 1.5 * enc.getAnimalCount();
            } else {
                newTicketPrice += 1 * enc.getAnimalCount();
            }
        }
        this.ticketPrice = newTicketPrice;
        // Melakukan update terhadap this.ticketPrice dengan rumus sebagai berikut
        // harga tiket baru = 0
        // Untuk setiap Enclosure dalam this.enclosures:
            // Apabila Enclosure bersifat safeForPetting:
            //     harga tiket baru += 1.5 * jumlah animal dalam enclosure
            // else:
            //     harga tiket baru += 1 * jumlah animal dalam enclosure 
    }

    public float getTicketPrice() {
        return this.ticketPrice;
        // getter untuk this.ticketPrice
    }

    public int getTotalAnimalCount() {
        int totalEncAnimalCount = 0;
        for (int i = 0; i < this.getEnclosureCount(); i++) {
            totalEncAnimalCount += this.enclosures.get(i).getAnimalCount();
        }
        return totalEncAnimalCount;
        // Mengembalikan jumlah total semua hewan yang ada pada semua enclosure dalam this.enclosures
    }

    public int getEnclosureCount() {
        return this.enclosures.size();
        // Mengembalikan jumlah enclosures dalam this.enclosures
    }
}