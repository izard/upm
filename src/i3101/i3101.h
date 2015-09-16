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
#pragma once

#include <mraa/gpio.h>

namespace upm {
  /**
   * @brief Intel 3101 memory
   * @defgroup i3101 libupm-i3101
   * @ingroup gpio electric
   */

  /**
   * @library i3101
   * @sensor i3101
   * @comname i3101 8 bytes memory
   * @type electric
   * @web http://www.antiquetech.com/?page_id=622
   * @con gpio
   *
   * @brief C++ API for Intel 3101 memory
   *
   * UPM module for the i3101
   * i3101 is the first static RAM chip ever produced.
   * It holds 16 4 bit words
   *
   * An example showing a simple test for reading and writing memory chip
   * @snippet i3101.cxx Interesting
   */
  class i3101 {
  public:
    /**
     * i3101 memory constructor
     *
     * @param cs pin for CS
     * @param write pin for write
     * @param a pins for address
     * @param d pins for data read and write
    */
    i3101();
    /**
     * i3101 Destructor
     */
    ~i3101();
    /**
     * Reads value at address
     *
     * @param addr - address [0-8]
     * @return value or -1 on error
     */
    int read(int addr);

    /**
     * Install an Interrupt Service Routine (ISR) to be called when
     * the appropriate magnetic field is detected.
     *
     * @param addr - address [0-8]
     * @param value - value [0-255]
     * @return 0 on success or -1 on error
     */
    int write(int addr, int value);

  private:
    int cs; int write; int a[]; int d[];
    mraa_gpio_context m_gpio_a[4];
    mraa_gpio_context m_gpio_d[4];
    mraa_gpio_context m_gpio_w[4];
    mraa_gpio_context m_gpio_cs;
    mraa_gpio_context m_gpio_write;
}
