import NavigationBar from "./assets/Navbar/NavigationBar.jsx";

import React, { useEffect, useState } from 'react';
import {Container} from "react-bootstrap";

function Home()
{
    return (
          <>
              <NavigationBar></NavigationBar>

              <Container>
                  <h1>Welcome to the Galactic News!</h1>
              </Container>
          </>
      );
}

export default Home
