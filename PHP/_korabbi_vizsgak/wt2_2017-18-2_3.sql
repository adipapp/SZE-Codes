-- phpMyAdmin SQL Dump
-- version 4.6.6
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Jun 13, 2018 at 03:34 PM
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
-- Table structure for table `film`
--

CREATE TABLE `film` (
  `id` int(11) NOT NULL COMMENT 'Egyedi filmazonosító',
  `cim` varchar(128) COLLATE utf8_hungarian_ci NOT NULL COMMENT 'Film címe',
  `plakat` varchar(128) COLLATE utf8_hungarian_ci NOT NULL COMMENT 'Plakát fájl neve',
  `leiras` text COLLATE utf8_hungarian_ci NOT NULL COMMENT 'Film ismertetője'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_hungarian_ci;

--
-- Dumping data for table `film`
--

INSERT INTO `film` (`id`, `cim`, `plakat`, `leiras`) VALUES
(1, 'The Shawshank Redemption', 'shawshank.jpg', 'Two imprisoned men bond over a number of years, finding solace and eventual redemption through acts of common decency.'),
(2, 'The Godfather', 'godfather.jpg', 'The aging patriarch of an organized crime dynasty transfers control of his clandestine empire to his reluctant son. '),
(3, 'The Godfather: Part II', 'godfather2.jpg', 'The early life and career of Vito Corleone in 1920s New York City is portrayed, while his son, Michael, expands and tightens his grip on the family crime syndicate.'),
(4, 'The Dark Knight', 'darkknight.jpg', 'When the menace known as the Joker emerges from his mysterious past, he wreaks havoc and chaos on the people of Gotham. The Dark Knight must accept one of the greatest psychological and physical tests of his ability to fight injustice. '),
(5, '12 Angry Men', '12angry.jpg', 'A jury holdout attempts to prevent a miscarriage of justice by forcing his colleagues to reconsider the evidence. ');

-- --------------------------------------------------------

--
-- Table structure for table `szavazat`
--

CREATE TABLE `szavazat` (
  `id` int(11) NOT NULL COMMENT 'Egyedi szavazat azonosító',
  `szavazat` int(11) NOT NULL COMMENT 'Pontérték [0, 10]',
  `film_id` int(11) NOT NULL COMMENT 'A film azonosítója'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_hungarian_ci;

--
-- Dumping data for table `szavazat`
--

INSERT INTO `szavazat` (`id`, `szavazat`, `film_id`) VALUES
(1, 8, 1),
(2, 9, 1),
(3, 10, 1),
(4, 9, 1);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `film`
--
ALTER TABLE `film`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `szavazat`
--
ALTER TABLE `szavazat`
  ADD PRIMARY KEY (`id`),
  ADD KEY `film_id` (`film_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `film`
--
ALTER TABLE `film`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT 'Egyedi filmazonosító', AUTO_INCREMENT=6;
--
-- AUTO_INCREMENT for table `szavazat`
--
ALTER TABLE `szavazat`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT 'Egyedi szavazat azonosító', AUTO_INCREMENT=5;
--
-- Constraints for dumped tables
--

--
-- Constraints for table `szavazat`
--
ALTER TABLE `szavazat`
  ADD CONSTRAINT `szavazat_ibfk_1` FOREIGN KEY (`film_id`) REFERENCES `film` (`id`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
