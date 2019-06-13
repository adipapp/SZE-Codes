-- phpMyAdmin SQL Dump
-- version 4.6.6
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: May 12, 2018 at 08:32 AM
-- Server version: 5.5.59-0+deb8u1
-- PHP Version: 7.0.27-1~dotdeb+8.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `hallgatok`
--

-- --------------------------------------------------------

--
-- Table structure for table `klima`
--

CREATE TABLE `klima` (
  `id` int(11) NOT NULL COMMENT 'Egyedi azonosító',
  `hutoTelj` float DEFAULT NULL COMMENT 'Hűtőteljesítmény',
  `futoTelj` float DEFAULT NULL COMMENT 'Fűtőteljesítmény',
  `SEER` float DEFAULT NULL COMMENT 'Hatékonyság (hűtés)',
  `SCOP` float DEFAULT NULL COMMENT 'Hatékonyság (fűtés)',
  `eOsztalyHutes` varchar(8) COLLATE utf8_hungarian_ci DEFAULT NULL COMMENT 'Energiaosztály (hűtés)',
  `eOsztalyFutes` varchar(8) COLLATE utf8_hungarian_ci DEFAULT NULL COMMENT 'Energiaosztály (fűtés)',
  `zajBelteri` varchar(16) COLLATE utf8_hungarian_ci DEFAULT NULL COMMENT 'Zajszint (beltéri)',
  `zajKulteri` varchar(8) COLLATE utf8_hungarian_ci DEFAULT NULL COMMENT 'Zajszint (kültéri)',
  `meret` varchar(64) COLLATE utf8_hungarian_ci DEFAULT NULL COMMENT 'Beltéri egység mérete',
  `kozeg` varchar(16) COLLATE utf8_hungarian_ci DEFAULT NULL COMMENT 'Hűtőközeg típusa',
  `biztositek` int(11) DEFAULT NULL COMMENT 'Ajánlott biztosíték',
  `aram` float DEFAULT NULL COMMENT 'Max. áramfelvétel',
  `garancia` varchar(16) COLLATE utf8_hungarian_ci DEFAULT NULL COMMENT 'Garancia',
  `brutto` int(11) DEFAULT NULL COMMENT 'Bruttó ár',
  `marka` varchar(128) COLLATE utf8_hungarian_ci NOT NULL COMMENT 'Készülék gyártója',
  `tipus` varchar(128) COLLATE utf8_hungarian_ci NOT NULL COMMENT 'Készülék típusa'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_hungarian_ci COMMENT='Oldalfali split klímaberendezések adatai';

--
-- Dumping data for table `klima`
--

INSERT INTO `klima` (`id`, `hutoTelj`, `futoTelj`, `SEER`, `SCOP`, `eOsztalyHutes`, `eOsztalyFutes`, `zajBelteri`, `zajKulteri`, `meret`, `kozeg`, `biztositek`, `aram`, `garancia`, `brutto`, `marka`, `tipus`) VALUES
(1, 3.5, 3.6, 6.1, 4.6, 'A++', 'A++', '24-51', '51', '790x275x200', 'R410A', NULL, NULL, '5', 165000, 'C&H Veritas', 'CH-S12FTXQWIFI'),
(2, 3.5, 3.7, 6.1, 4, 'A++', 'A+', '31-42', '53', '845x289x209', 'R32', 10, 7.2, '5', 195000, 'NORD RAC NUBIAN NEW AGE', 'NWH12QB-K6DNC4C'),
(3, 3.5, 3.8, 6.1, 4, 'A++', 'A+', '29-42', '52', '896x320x159', 'R410A', 10, NULL, '5', 195000, 'Nord Mojave', 'NWH12UB'),
(4, 3.5, 3.5, 6.43, 4.07, 'A++', 'A+', '27-42', '51', '750x285x200', 'R410A', NULL, 4.84, '3+2', 165000, 'Rcool Display 12', 'GRA12B7-GRA12K7'),
(5, 3.5, 3.5, 6.16, 4.07, 'A++', 'A+', '30-39', '52', '800x300x198', 'R410A', NULL, 4.97, '3+2', 192000, 'RCOOL Prime2', 'GRW12B8410/GRW12K8410 WIFI'),
(6, 3.5, 3.82, 6.1, 4, 'A++', 'A++', '28.5-41.5', '56', '805x285x205', 'R410A', NULL, 10, '5', 168000, 'Midea Blanc', 'MSMABU-12HRDN1-QRD0G'),
(7, 3.5, 3.84, 7.5, 4.6, 'A++', 'A++', '24-40', '62', '810x300x200', 'R32', NULL, 10, '5', 212000, 'Midea Mission II.', 'MSMBBU-12HRFN8-QRD6GW WIFI'),
(8, 3.3, 3.5, 6.05, 4.06, 'A+', 'A+', '39 (max)', '55', '770x283x216', NULL, NULL, NULL, '2', 190000, 'Daikin', 'FTXB35C-RXB35C'),
(9, 3.75, 4.6, 5.85, 3.8, 'A+', 'A', '25-44', NULL, '280x780x218', 'R410A', 16, NULL, '10', 199000, 'Hitachi Economy', 'RAK35PEC / RAC35WEC'),
(10, 3.5, 4.2, 7.2, 4.6, 'A++', 'A++', '25-43', '63', '295x900x230', NULL, NULL, NULL, '10', 259000, 'Hitachi Standard', 'RAK 35 RPC / RAC 35 WPC');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `klima`
--
ALTER TABLE `klima`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `klima`
--
ALTER TABLE `klima`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT 'Egyedi azonosító', AUTO_INCREMENT=11;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
