<?php
   class MyDB extends SQLite3 {
      function __construct() {
         $this->open('casino_users.db');
      }
   }
   
   $db = new MyDB();
   if(!$db){
      echo $db->lastErrorMsg();
   } else {
      echo "Opened database successfully\n";
   }

   $db->exec( "CREATE TABLE users(ID INTEGER, name TEXT, password TEXT, desc TEXT)" );
   
   $sql =<<<EOF
      INSERT INTO users (ID,name,password,desc)
      VALUES (1, 'Lex', 'lexIsc00lh4ck3r', 'reverser');

      INSERT INTO users (ID,name,password,desc)
      VALUES (2, 'Allen', '4llY0urD4t415my', 'admin');

      INSERT INTO users (ID,name,password,desc)
      VALUES (3, 'Keller', 'kill3rm4n', 'weber');

      INSERT INTO users (ID,name,password,desc)
      VALUES (4, 'Anon', '62d893ca7da8720bbbd89ac655dde92543645fff', 'just Anon');
EOF;

   $ret = $db->exec($sql);
   if(!$ret) {
      echo $db->lastErrorMsg();
   } else {
      echo "Records created successfully\n";
   }
   $db->close();
?>