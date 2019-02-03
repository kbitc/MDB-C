static String

uint8_t sniff() {
  if (mdb.available) {
    debug.println("%d", mdb.read());
  }
/*if (mdb.available) {
  debug.println("                         %d", mdb.read());
  }*/
}

uint8_t parse(uint8_t address) {

}
