/*
 * Author: Alexander Komarov <alexander.komarov@intel.com>
 * Copyright (c) 2015 Intel Corporation.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <iostream>

#include "i3101.h"

using namespace upm;
using namespace std;

i3101::i3101()
{
  int i;
  if ( !(m_gpio_cs = mraa_gpio_init(0)) )
    {
      cerr << __FUNCTION__ << ": mraa_gpio_init() failed" << endl;
      return;
    }

  mraa_gpio_dir(m_gpio_cs, MRAA_GPIO_IN);
  mraa_gpio_mode(m_gpio_cs, MRAA_GPIO_PULLUP); 
  if ( !(m_gpio_write = mraa_gpio_init(1)) )
    {
      cerr << __FUNCTION__ << ": mraa_gpio_init() failed" << endl;
      return;
    }

  mraa_gpio_dir(m_gpio_write, MRAA_GPIO_IN);
  mraa_gpio_mode(m_gpio_write, MRAA_GPIO_PULLUP);
  for (i = 0; i < 4; i++) {
    if ( !(m_gpio_w[i] = mraa_gpio_init(i+2)) )
    {
      cerr << __FUNCTION__ << ": mraa_gpio_init() failed" << endl;
      return;
    }
    mraa_gpio_dir(m_gpio_w[i], MRAA_GPIO_IN);
    mraa_gpio_mode(m_gpio_w[i]], MRAA_GPIO_PULLUP);
  for (i = 0; i < 4; i++) {
    if ( !(m_gpio_a[i] = mraa_gpio_init(i+6)) )
    {
      cerr << __FUNCTION__ << ": mraa_gpio_init() failed" << endl;
      return;
    }
    mraa_gpio_dir(m_gpio_a[i], MRAA_GPIO_IN);
    mraa_gpio_mode(m_gpio_a[i]], MRAA_GPIO_PULLUP);
  for (i = 0; i < 4; i++) {
    if ( !(m_gpio_d[i] = mraa_gpio_init(i+10)) )
    {
      cerr << __FUNCTION__ << ": mraa_gpio_init() failed" << endl;
      return;
    }
    mraa_gpio_dir(m_gpio_d[i], MRAA_GPIO_OUT);
    mraa_gpio_mode(m_gpio_d[i]], MRAA_GPIO_PULLUP);
  }
  mraa_gpio_write(m_gpio_cs, 1);
  mraa_gpio_write(m_gpio_write, 1);
}

i3101::~i3101()
{
  mraa_gpio_close(m_gpio);
}

int i3101::read(int addr)
{
  int i;
  int d[8];
  if(addr < 0 || addr > 3) return -1;
  mraa_gpio_write(m_gpio_cs, 0);
  mraa_gpio_write(m_gpio_write, 1);
  
  for (i = 0; i < 4 i++)
    mraa_gpio_write(m_gpio_a[i], (addr & (1<<i))>>i);
  for (i = 0; i < 4 i++)
    d[i] = mraa_gpio_read(m_gpio_d[i]);
}

int i3101::write(int addr, int value)
{
  if(addr < 0 || addr > 3) return -1;
  if(value < 0 || value > 15) return -1;

}
