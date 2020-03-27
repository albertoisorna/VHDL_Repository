--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   13:59:50 11/25/2016
-- Design Name:   
-- Module Name:   C:/Users/Alberto/Documents/ISE_projects/PROYECT_SERPIENTE/TB_TOPITO.vhd
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
--USE ieee.numeric_std.ALL;
 
ENTITY TB_TOPITO IS
END TB_TOPITO;
 
ARCHITECTURE behavior OF TB_TOPITO IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT TOP_ITO
    PORT(
         clk : IN  std_logic;
         reset : IN  std_logic;
         VS : OUT  std_logic;
         HS : OUT  std_logic;
         RED : OUT  std_logic_vector(2 downto 0);
         GRN : OUT  std_logic_vector(2 downto 0);
         BLUE : OUT  std_logic_vector(1 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal reset : std_logic := '0';

 	--Outputs
   signal VS : std_logic;
   signal HS : std_logic;
   signal RED : std_logic_vector(2 downto 0);
   signal GRN : std_logic_vector(2 downto 0);
   signal BLUE : std_logic_vector(1 downto 0);

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: TOP_ITO PORT MAP (
          clk => clk,
          reset => reset,
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
      -- insert stimulus here 

      wait;
   end process;

END;
