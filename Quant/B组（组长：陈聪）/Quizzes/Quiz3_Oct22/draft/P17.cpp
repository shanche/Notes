void roboMeet() {
            bool reachedZero = false;
            while( !meet() ) {
                  if(reachedZero) {
                        moveLeft();
                        moveLeft();
                  } else {
                        moveLeft();
                        moveLeft();
                        moveRight();
                  }
                  if( at-zero() ) {
                        reachedZero = true;
                  }
            }
      }