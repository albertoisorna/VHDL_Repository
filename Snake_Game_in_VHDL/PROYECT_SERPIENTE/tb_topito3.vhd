--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   17:30:55 12/01/2016
-- Design Name:   
-- Module Name:   C:/Users/Alberto/Documents/ISE_projects/PROYECT_SERPIENTE/tb_topito3.vhd
-- Project Name:  PROYECT_SERPIENTE
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: TOP_ITO
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
USE ieee.numeric_std.ALL;
 
ENTITY tb_topito3 IS
END tb_topito3;
 
ARCHITECTURE behavior OF tb_topito3 IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT TOP_ITO
    PORT(
         clk : IN  std_logic;
         reset : IN  std_logic;
         upin : IN  std_logic;
         downin : IN  std_logic;
         leftin : IN  std_logic;
         rightin : IN  std_logic;
         swein : IN  std_logic;
         VS : OUT  std_logic;
         HS : OUT  std_logic;
         RED : OUT  std_logic;
         GRN : OUT  std_logic;
         BLUE : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal reset : std_logic := '0';
   signal upin : std_logic := '0';
   signal downin : std_logic := '0';
   signal leftin : std_logic := '0';
   signal rightin : std_logic := '0';
   signal swein : std_logic := '0';

 	--Outputs
   signal VS : std_logic;
   signal HS : std_logic;
   signal RED : std_logic;
   signal GRN : std_logic;
   signal BLUE : std_logic;

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: TOP_ITO PORT MAP (
          clk => clk,
          reset => reset,
          upin => upin,
          downin => downin,
          leftin => leftin,
          rightin => rightin,
          swein => swein,
          VS => VS,
          HS => HS,
          RED => RED,
          GRN => GRN,
          BLUE => BLUE
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      reset<='1';   
      wait for clk_period*10;
		reset<='0';
		wait for clk_period*10;
		swein<='1';
		wait for clk_period*10;
		rightin<='1';
      wait;
   end process;

END;
