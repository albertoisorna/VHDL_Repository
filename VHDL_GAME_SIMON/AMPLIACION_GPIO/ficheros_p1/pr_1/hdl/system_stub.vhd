-------------------------------------------------------------------------------
-- system_stub.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

entity system_stub is
  port (
    fpga_0_USB_UART_RX_pin : in std_logic;
    fpga_0_USB_UART_TX_pin : out std_logic;
    fpga_0_LEDs_4Bits_GPIO_IO_O_pin : out std_logic_vector(0 to 3);
    fpga_0_DIP_Switch_4Bits_GPIO_IO_I_pin : in std_logic_vector(0 to 3);
    fpga_0_SPI_FLASH_SCK_pin : inout std_logic;
    fpga_0_SPI_FLASH_MISO_pin : inout std_logic;
    fpga_0_SPI_FLASH_MOSI_pin : inout std_logic;
    fpga_0_SPI_FLASH_SS_pin : inout std_logic;
    fpga_0_SPI_FLASH_SPI_HOLDn_pin : out std_logic;
    fpga_0_SPI_FLASH_SPI_Wn_pin : out std_logic;
    fpga_0_MCB3_LPDDR_mcbx_dram_addr_pin : out std_logic_vector(12 downto 0);
    fpga_0_MCB3_LPDDR_mcbx_dram_ba_pin : out std_logic_vector(1 downto 0);
    fpga_0_MCB3_LPDDR_mcbx_dram_ras_n_pin : out std_logic;
    fpga_0_MCB3_LPDDR_mcbx_dram_cas_n_pin : out std_logic;
    fpga_0_MCB3_LPDDR_mcbx_dram_we_n_pin : out std_logic;
    fpga_0_MCB3_LPDDR_mcbx_dram_cke_pin : out std_logic;
    fpga_0_MCB3_LPDDR_mcbx_dram_clk_pin : out std_logic;
    fpga_0_MCB3_LPDDR_mcbx_dram_clk_n_pin : out std_logic;
    fpga_0_MCB3_LPDDR_mcbx_dram_dq_pin : inout std_logic_vector(15 downto 0);
    fpga_0_MCB3_LPDDR_mcbx_dram_dqs_pin : inout std_logic;
    fpga_0_MCB3_LPDDR_mcbx_dram_udqs_pin : inout std_logic;
    fpga_0_MCB3_LPDDR_mcbx_dram_udm_pin : out std_logic;
    fpga_0_MCB3_LPDDR_mcbx_dram_ldm_pin : out std_logic;
    fpga_0_MCB3_LPDDR_rzq_pin : inout std_logic;
    fpga_0_Ethernet_MAC_PHY_tx_clk_pin : in std_logic;
    fpga_0_Ethernet_MAC_PHY_rx_clk_pin : in std_logic;
    fpga_0_Ethernet_MAC_PHY_crs_pin : in std_logic;
    fpga_0_Ethernet_MAC_PHY_dv_pin : in std_logic;
    fpga_0_Ethernet_MAC_PHY_rx_data_pin : in std_logic_vector(3 downto 0);
    fpga_0_Ethernet_MAC_PHY_col_pin : in std_logic;
    fpga_0_Ethernet_MAC_PHY_rx_er_pin : in std_logic;
    fpga_0_Ethernet_MAC_PHY_rst_n_pin : out std_logic;
    fpga_0_Ethernet_MAC_PHY_tx_en_pin : out std_logic;
    fpga_0_Ethernet_MAC_PHY_tx_data_pin : out std_logic_vector(3 downto 0);
    fpga_0_Ethernet_MAC_PHY_MDC_pin : out std_logic;
    fpga_0_Ethernet_MAC_PHY_MDIO_pin : inout std_logic;
    fpga_0_CDCE913_I2C_Sda_pin : inout std_logic;
    fpga_0_CDCE913_I2C_Scl_pin : inout std_logic;
    fpga_0_clk_1_sys_clk_pin : in std_logic;
    fpga_0_rst_1_sys_rst_pin : in std_logic;
    GPIO_KEYPAD_GPIO_IO_I_pin : in std_logic_vector(0 to 3);
    GPIO_KEYPAD_GPIO2_IO_O_pin : out std_logic_vector(0 to 3);
    simon_periferico_0_SIMON_KO_pin : out std_logic_vector(0 to 3);
    simon_periferico_0_SIMON_KI_pin : in std_logic_vector(0 to 3);
    GPIO_DISPLAY_GPIO_IO_O_pin : out std_logic_vector(0 to 7)
  );
end system_stub;

architecture STRUCTURE of system_stub is

  component system is
    port (
      fpga_0_USB_UART_RX_pin : in std_logic;
      fpga_0_USB_UART_TX_pin : out std_logic;
      fpga_0_LEDs_4Bits_GPIO_IO_O_pin : out std_logic_vector(0 to 3);
      fpga_0_DIP_Switch_4Bits_GPIO_IO_I_pin : in std_logic_vector(0 to 3);
      fpga_0_SPI_FLASH_SCK_pin : inout std_logic;
      fpga_0_SPI_FLASH_MISO_pin : inout std_logic;
      fpga_0_SPI_FLASH_MOSI_pin : inout std_logic;
      fpga_0_SPI_FLASH_SS_pin : inout std_logic;
      fpga_0_SPI_FLASH_SPI_HOLDn_pin : out std_logic;
      fpga_0_SPI_FLASH_SPI_Wn_pin : out std_logic;
      fpga_0_MCB3_LPDDR_mcbx_dram_addr_pin : out std_logic_vector(12 downto 0);
      fpga_0_MCB3_LPDDR_mcbx_dram_ba_pin : out std_logic_vector(1 downto 0);
      fpga_0_MCB3_LPDDR_mcbx_dram_ras_n_pin : out std_logic;
      fpga_0_MCB3_LPDDR_mcbx_dram_cas_n_pin : out std_logic;
      fpga_0_MCB3_LPDDR_mcbx_dram_we_n_pin : out std_logic;
      fpga_0_MCB3_LPDDR_mcbx_dram_cke_pin : out std_logic;
      fpga_0_MCB3_LPDDR_mcbx_dram_clk_pin : out std_logic;
      fpga_0_MCB3_LPDDR_mcbx_dram_clk_n_pin : out std_logic;
      fpga_0_MCB3_LPDDR_mcbx_dram_dq_pin : inout std_logic_vector(15 downto 0);
      fpga_0_MCB3_LPDDR_mcbx_dram_dqs_pin : inout std_logic;
      fpga_0_MCB3_LPDDR_mcbx_dram_udqs_pin : inout std_logic;
      fpga_0_MCB3_LPDDR_mcbx_dram_udm_pin : out std_logic;
      fpga_0_MCB3_LPDDR_mcbx_dram_ldm_pin : out std_logic;
      fpga_0_MCB3_LPDDR_rzq_pin : inout std_logic;
      fpga_0_Ethernet_MAC_PHY_tx_clk_pin : in std_logic;
      fpga_0_Ethernet_MAC_PHY_rx_clk_pin : in std_logic;
      fpga_0_Ethernet_MAC_PHY_crs_pin : in std_logic;
      fpga_0_Ethernet_MAC_PHY_dv_pin : in std_logic;
      fpga_0_Ethernet_MAC_PHY_rx_data_pin : in std_logic_vector(3 downto 0);
      fpga_0_Ethernet_MAC_PHY_col_pin : in std_logic;
      fpga_0_Ethernet_MAC_PHY_rx_er_pin : in std_logic;
      fpga_0_Ethernet_MAC_PHY_rst_n_pin : out std_logic;
      fpga_0_Ethernet_MAC_PHY_tx_en_pin : out std_logic;
      fpga_0_Ethernet_MAC_PHY_tx_data_pin : out std_logic_vector(3 downto 0);
      fpga_0_Ethernet_MAC_PHY_MDC_pin : out std_logic;
      fpga_0_Ethernet_MAC_PHY_MDIO_pin : inout std_logic;
      fpga_0_CDCE913_I2C_Sda_pin : inout std_logic;
      fpga_0_CDCE913_I2C_Scl_pin : inout std_logic;
      fpga_0_clk_1_sys_clk_pin : in std_logic;
      fpga_0_rst_1_sys_rst_pin : in std_logic;
      GPIO_KEYPAD_GPIO_IO_I_pin : in std_logic_vector(0 to 3);
      GPIO_KEYPAD_GPIO2_IO_O_pin : out std_logic_vector(0 to 3);
      simon_periferico_0_SIMON_KO_pin : out std_logic_vector(0 to 3);
      simon_periferico_0_SIMON_KI_pin : in std_logic_vector(0 to 3);
      GPIO_DISPLAY_GPIO_IO_O_pin : out std_logic_vector(0 to 7)
    );
  end component;

  attribute BUFFER_TYPE : STRING;
  attribute BOX_TYPE : STRING;
  attribute BUFFER_TYPE of fpga_0_Ethernet_MAC_PHY_tx_clk_pin : signal is "IBUF";
  attribute BUFFER_TYPE of fpga_0_Ethernet_MAC_PHY_rx_clk_pin : signal is "IBUF";
  attribute BOX_TYPE of system : component is "user_black_box";

begin

  system_i : system
    port map (
      fpga_0_USB_UART_RX_pin => fpga_0_USB_UART_RX_pin,
      fpga_0_USB_UART_TX_pin => fpga_0_USB_UART_TX_pin,
      fpga_0_LEDs_4Bits_GPIO_IO_O_pin => fpga_0_LEDs_4Bits_GPIO_IO_O_pin,
      fpga_0_DIP_Switch_4Bits_GPIO_IO_I_pin => fpga_0_DIP_Switch_4Bits_GPIO_IO_I_pin,
      fpga_0_SPI_FLASH_SCK_pin => fpga_0_SPI_FLASH_SCK_pin,
      fpga_0_SPI_FLASH_MISO_pin => fpga_0_SPI_FLASH_MISO_pin,
      fpga_0_SPI_FLASH_MOSI_pin => fpga_0_SPI_FLASH_MOSI_pin,
      fpga_0_SPI_FLASH_SS_pin => fpga_0_SPI_FLASH_SS_pin,
      fpga_0_SPI_FLASH_SPI_HOLDn_pin => fpga_0_SPI_FLASH_SPI_HOLDn_pin,
      fpga_0_SPI_FLASH_SPI_Wn_pin => fpga_0_SPI_FLASH_SPI_Wn_pin,
      fpga_0_MCB3_LPDDR_mcbx_dram_addr_pin => fpga_0_MCB3_LPDDR_mcbx_dram_addr_pin,
      fpga_0_MCB3_LPDDR_mcbx_dram_ba_pin => fpga_0_MCB3_LPDDR_mcbx_dram_ba_pin,
      fpga_0_MCB3_LPDDR_mcbx_dram_ras_n_pin => fpga_0_MCB3_LPDDR_mcbx_dram_ras_n_pin,
      fpga_0_MCB3_LPDDR_mcbx_dram_cas_n_pin => fpga_0_MCB3_LPDDR_mcbx_dram_cas_n_pin,
      fpga_0_MCB3_LPDDR_mcbx_dram_we_n_pin => fpga_0_MCB3_LPDDR_mcbx_dram_we_n_pin,
      fpga_0_MCB3_LPDDR_mcbx_dram_cke_pin => fpga_0_MCB3_LPDDR_mcbx_dram_cke_pin,
      fpga_0_MCB3_LPDDR_mcbx_dram_clk_pin => fpga_0_MCB3_LPDDR_mcbx_dram_clk_pin,
      fpga_0_MCB3_LPDDR_mcbx_dram_clk_n_pin => fpga_0_MCB3_LPDDR_mcbx_dram_clk_n_pin,
      fpga_0_MCB3_LPDDR_mcbx_dram_dq_pin => fpga_0_MCB3_LPDDR_mcbx_dram_dq_pin,
      fpga_0_MCB3_LPDDR_mcbx_dram_dqs_pin => fpga_0_MCB3_LPDDR_mcbx_dram_dqs_pin,
      fpga_0_MCB3_LPDDR_mcbx_dram_udqs_pin => fpga_0_MCB3_LPDDR_mcbx_dram_udqs_pin,
      fpga_0_MCB3_LPDDR_mcbx_dram_udm_pin => fpga_0_MCB3_LPDDR_mcbx_dram_udm_pin,
      fpga_0_MCB3_LPDDR_mcbx_dram_ldm_pin => fpga_0_MCB3_LPDDR_mcbx_dram_ldm_pin,
      fpga_0_MCB3_LPDDR_rzq_pin => fpga_0_MCB3_LPDDR_rzq_pin,
      fpga_0_Ethernet_MAC_PHY_tx_clk_pin => fpga_0_Ethernet_MAC_PHY_tx_clk_pin,
      fpga_0_Ethernet_MAC_PHY_rx_clk_pin => fpga_0_Ethernet_MAC_PHY_rx_clk_pin,
      fpga_0_Ethernet_MAC_PHY_crs_pin => fpga_0_Ethernet_MAC_PHY_crs_pin,
      fpga_0_Ethernet_MAC_PHY_dv_pin => fpga_0_Ethernet_MAC_PHY_dv_pin,
      fpga_0_Ethernet_MAC_PHY_rx_data_pin => fpga_0_Ethernet_MAC_PHY_rx_data_pin,
      fpga_0_Ethernet_MAC_PHY_col_pin => fpga_0_Ethernet_MAC_PHY_col_pin,
      fpga_0_Ethernet_MAC_PHY_rx_er_pin => fpga_0_Ethernet_MAC_PHY_rx_er_pin,
      fpga_0_Ethernet_MAC_PHY_rst_n_pin => fpga_0_Ethernet_MAC_PHY_rst_n_pin,
      fpga_0_Ethernet_MAC_PHY_tx_en_pin => fpga_0_Ethernet_MAC_PHY_tx_en_pin,
      fpga_0_Ethernet_MAC_PHY_tx_data_pin => fpga_0_Ethernet_MAC_PHY_tx_data_pin,
      fpga_0_Ethernet_MAC_PHY_MDC_pin => fpga_0_Ethernet_MAC_PHY_MDC_pin,
      fpga_0_Ethernet_MAC_PHY_MDIO_pin => fpga_0_Ethernet_MAC_PHY_MDIO_pin,
      fpga_0_CDCE913_I2C_Sda_pin => fpga_0_CDCE913_I2C_Sda_pin,
      fpga_0_CDCE913_I2C_Scl_pin => fpga_0_CDCE913_I2C_Scl_pin,
      fpga_0_clk_1_sys_clk_pin => fpga_0_clk_1_sys_clk_pin,
      fpga_0_rst_1_sys_rst_pin => fpga_0_rst_1_sys_rst_pin,
      GPIO_KEYPAD_GPIO_IO_I_pin => GPIO_KEYPAD_GPIO_IO_I_pin,
      GPIO_KEYPAD_GPIO2_IO_O_pin => GPIO_KEYPAD_GPIO2_IO_O_pin,
      simon_periferico_0_SIMON_KO_pin => simon_periferico_0_SIMON_KO_pin,
      simon_periferico_0_SIMON_KI_pin => simon_periferico_0_SIMON_KI_pin,
      GPIO_DISPLAY_GPIO_IO_O_pin => GPIO_DISPLAY_GPIO_IO_O_pin
    );

end architecture STRUCTURE;

